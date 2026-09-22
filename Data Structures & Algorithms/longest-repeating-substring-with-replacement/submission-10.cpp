class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);

        int max_count = 0;
        int l = 0;
        for(int i = 0; i < s.size(); i++){
            counts[s[i]-'A']++;
            int max_freq = *max_element(counts.begin(), counts.end());

            while((i-l+1) - max_freq > k){
                counts[s[l]-'A']--;
                l++;
            }

            max_count = max((i-l+1), max_count);
        }

        return max_count;
    }
};
