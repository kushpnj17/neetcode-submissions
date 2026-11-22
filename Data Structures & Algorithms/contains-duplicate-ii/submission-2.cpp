class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int upper_bound = k;
        int r = 0;
        int l = 0;
        unordered_set<int> uset;

        while(r < nums.size()){
            while(r <= upper_bound && r < nums.size()){
                if(uset.count(nums[r])) return true;
                uset.insert(nums[r]);
                r++;
            }

            while(abs(r-l) > k){
                uset.erase(nums[l]);
                l++;
                upper_bound++;
            }
        }

        return false;
    }
};