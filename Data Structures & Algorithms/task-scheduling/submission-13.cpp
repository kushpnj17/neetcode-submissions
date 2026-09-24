class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        for(char c : tasks) {
            umap[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto p : umap) {
            pq.push({p.second, p.first});
        }

        int cycles = 0;
        queue<pair<int, char>> q;
        while(!q.empty() || !pq.empty()){
            cycles++;

            if(!pq.empty()) {
                auto p = pq.top(); pq.pop();
                umap[p.second]--;
                if(p.first > 1){
                    q.push({cycles + n, p.second});
                }
            }

            if(!q.empty() && q.front().first == cycles) {
                pq.push({umap[q.front().second], q.front().second});
                q.pop();
            }
        }

        return cycles;
    }
};
