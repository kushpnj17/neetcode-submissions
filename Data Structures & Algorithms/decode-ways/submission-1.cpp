class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        // n = 3
        // dp.size = 4
        // i = 2
        // i+1 = 3
        // i+2 = 4

        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            dp[i] = dp[i+1];
            if(i+1 < n){
                int num = (s[i]-'0') * 10 + (s[i+1]-'0');
                if(num <= 26){
                    dp[i] += dp[i+2];
                }
            }
        }

        return dp[0];
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
