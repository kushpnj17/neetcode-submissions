class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        vector<int> counts(26,0);

        for(int i = 0; i < s.size(); i++){
            counts[s[i]-'A']++;
            int freq = *max_element(counts.begin(), counts.end());

            while((i-l+1) - freq > k){
                counts[s[l]-'A']--;
                l++;
            }

            res = max(res, (i-l+1));
        }

        return res;
    }
};

// while(win_len - max_freq_char <= k)