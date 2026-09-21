class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(int n : nums){
            counts[n]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto p : counts){
            pq.push({p.second, p.first});
        }

        vector<int> res;
        while(res.size() < k){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
