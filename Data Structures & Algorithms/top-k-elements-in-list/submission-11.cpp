class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int n : nums){
            umap[n]++;
        }

        vector<vector<int>> frequency(nums.size()+1);
        for(auto p : umap){
            frequency[p.second].push_back(p.first);
        }

        vector<int> res;
        for(int i = frequency.size() - 1; i >= 0; i--){
            for(int n : frequency[i]){
                if(res.size() < k){
                    res.push_back(n);
                } else {
                    return res;
                }
            }
        }

        return res;
    }
};
