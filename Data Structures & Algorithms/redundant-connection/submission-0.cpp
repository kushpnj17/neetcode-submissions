class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> umap;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            umap[u].push_back(v);
            umap[v].push_back(u);

            unordered_set<int> visited;
            if(!dfs(u, -1, umap, visited)){
                return {u,v};
            }
        }

        return {};
    }

    bool dfs(int u, int prev, unordered_map<int, vector<int>> &umap, unordered_set<int> &visited){
        if(visited.count(u)) return false;

        visited.insert(u);

        for(int n : umap[u]){
            if(n == prev){
                continue;
            }

            if(!dfs(n, u, umap, visited)){
                return false;
            }
        }

        return true;
    }
};
