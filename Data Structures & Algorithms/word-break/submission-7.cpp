class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, 0);

        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            string t;
            for(int j = i; j < i+20 && j < s.size(); j++){
                t += s[j];
                if(dict.count(t) && dp[j+1]){
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0];
    }
};
