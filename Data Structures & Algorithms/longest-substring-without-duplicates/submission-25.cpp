class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int l = 0;
        int r = 0;
        int max_length = 0;
        while(r < s.size()){
            while(r < s.size() && uset.find(s[r]) == uset.end()){
                uset.insert(s[r]);
                r++;
            }

            max_length = max(max_length, r-l);
            
            while(uset.find(s[r]) != uset.end()){
                uset.erase(s[l]);
                l++;
            }

        }

        return max_length;
    }
};
