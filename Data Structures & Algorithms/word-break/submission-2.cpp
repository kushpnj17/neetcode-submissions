class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1, -1);

        return solve(s, 0, dict, dp);
    }

    bool solve(string &s, int i, unordered_set<string> &dict, vector<int> &dp) {
        if(i == s.size()) dp[i] = 1;

        if(dp[i] != -1) return dp[i];

        string t;
        for(int j = i; j < s.size(); j++){
            t += s[j];
            if(dict.count(t) && solve(s, j+1, dict, dp)){
                dp[i] = 1;
                return dp[i];
            }
        }

        dp[i] = 0;
        return false;
    }
};
