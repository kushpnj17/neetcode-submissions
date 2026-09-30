class Solution {
    int cycle_start = -1;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> umap;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }

        unordered_set<int> visited;
        unordered_set<int> cycle;
        dfs(1, -1, umap, visited, cycle);

        for(int i = edges.size()-1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(cycle.count(u) && cycle.count(v)){
                return {u,v};
            }
        }

        return {};
    }

    bool dfs(int u, int prev, unordered_map<int, vector<int>> &umap, unordered_set<int> &visited, unordered_set<int> &cycle){
        if(visited.count(u)) {
            cycle_start = u;
            return false;
        }

        visited.insert(u);

        for(int n : umap[u]){
            if(n == prev){
                continue;
            }

            if(!dfs(n, u, umap, visited, cycle)){
                if(cycle_start != -1){
                    cycle.insert(u);
                }
                
                if (cycle_start == u){
                    cycle_start = -1;
                }
                return false;
            }
        }
        return true;
    }
};
