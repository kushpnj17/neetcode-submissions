class Solution {
    unordered_map<int, vector<int>> umap; 
    unordered_set<int> visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto &v : edges){
            umap[v[0]].push_back(v[1]);
            umap[v[1]].push_back(v[0]);
        }

        if(!dfs(0, -1)) return false;
        return visited.size() == n;
    }

    bool dfs(int cur, int prev){
        if(visited.count(cur)) {
            return false;
        }
        cout << "cur: " << cur << endl;
        visited.insert(cur);

        for(int n : umap[cur]){
            if(n == prev) continue;
            
            if(!dfs(n, cur)){
                return false;
            }
        }

        return true;
    }
};
