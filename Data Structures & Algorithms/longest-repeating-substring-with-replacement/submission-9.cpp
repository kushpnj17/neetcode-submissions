class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);

        int max_count = 0;
        int l = 0;
        for(int i = 0; i < s.size(); i++){
            counts[s[i]-'A']++;
            int range = i-l+1;
            int max_freq = *max_element(counts.begin(), counts.end());

            if(range - max_freq <= k) {
                max_count = max(max_count, range);
            }

            while(range - max_freq > k){
                counts[s[l]-'A']--;
                l++;
                max_freq = *max_element(counts.begin(), counts.end());
                range = i-l+1;
            }
        }

        return max_count;
    }
};
