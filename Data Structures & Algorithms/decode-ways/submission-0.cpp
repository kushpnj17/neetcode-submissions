class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }

    int solve(string &s, int i, vector<int> &dp){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int one = solve(s, i+1, dp);

        int num = -1;
        if(i+1 < s.size()) num = (s[i] - '0') * 10 + (s[i+1] - '0');
        if(num != -1 && num <= 26){
            dp[i] = solve(s, i+2, dp) + one;
            return dp[i];
        }

        dp[i] = one;
        return dp[i];
    }
};
