class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++) {
            int seen = target - nums[i];
            if(umap.find(seen) != umap.end()){
                return {umap[seen], i};
            }

            umap[nums[i]] = i;
        }

        return {};
    }
};
