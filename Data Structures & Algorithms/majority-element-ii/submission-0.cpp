class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int n : nums) {
            umap[n]++;
        }

        vector<int> res;
        for(auto p : umap){
            if(p.second > nums.size() / 3){
                res.push_back(p.first);
            }
        }

        return res;
    }
};