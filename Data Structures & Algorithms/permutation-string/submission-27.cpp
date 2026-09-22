class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        vector<int> s1_counts(26,0);
        for(char c : s1){
            s1_counts[c-'a']++;
        }

        vector<int> s2_counts(26, 0);
        for(int i = 0; i < s1.size(); i++){
            s2_counts[s2[i]-'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(s1_counts[i] == s2_counts[i]) matches++;
        }

        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++){
            if(matches == 26) return true;

            s2_counts[s2[l]-'a']--;
            if(s2_counts[s2[l]-'a'] == s1_counts[s2[l]-'a']){
                matches++;
            } else if (s1_counts[s2[l]-'a'] - 1 == s2_counts[s2[l]-'a']){
                matches--;
            }
            l++;

            s2_counts[s2[r]-'a']++;
            if(s2_counts[s2[r]-'a'] == s1_counts[s2[r]-'a']){
                matches++;
            } else if (s1_counts[s2[r]-'a'] + 1 == s2_counts[s2[r]-'a']){
                matches--;
            }
        }

        return matches == 26;
    }
};

// s1: ab
// s2: cba
// r: 2
// l: 0




