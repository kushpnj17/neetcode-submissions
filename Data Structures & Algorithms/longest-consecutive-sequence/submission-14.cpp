class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int max_count = 0;
        for(int n : nums) {
            if(uset.find(n-1) != uset.end()) continue;
            
            int count = 0;
            int start = n;
            while(uset.find(start) != uset.end()){
                count++;
                start++;
            }

            max_count = max(count, max_count);
        }

        return max_count;
    }
};
