class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // vector<int> dp(n+1, 0);

        int prev1 = 1;
        int prev2 = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0') {
                prev2 = prev1;
                prev1 = 0;
                continue;
            }

            int next = prev1;
            if(i+1 < n){
                int num = (s[i]-'0') * 10 + (s[i+1]-'0');
                if(num <= 26){
                    next += prev2;
                }
            }

            prev2 = prev1;
            prev1 = next;
        }

        return prev1;
    }
};
