class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1,0);
        unordered_map<int, vector<int>> umap;
        for(auto &v : edges){
            indegree[v[0]]++;
            indegree[v[1]]++;
            umap[v[0]].push_back(v[1]);
            umap[v[1]].push_back(v[0]);
        }

        queue<int> q;
        for(int i = 1; i < n+1; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int p = q.front(); q.pop();

            for(int k : umap[p]){
                indegree[k]--;
                if(indegree[k] == 1){
                    q.push(k);
                }
            }
        }

        unordered_set<int> cycle;
        for(int i = 1; i < n+1; i++){
            if(indegree[i] > 1){
                cycle.insert(i);
            }
        }

        for(int i = n - 1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(cycle.count(u) && cycle.count(v)){
                return {u,v};
            }
        }

        return {};
    }
};
