class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> umap;
        for(auto &v : edges){
            umap[v[0]].push_back(v[1]);
            umap[v[1]].push_back(v[0]);
        }

        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited.count(i)){
                count++;
                visited.insert(i);
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int p = q.front(); q.pop();
                    
                    for(int v : umap[p]){
                        if(!visited.count(v)){
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }
        }

        return count;
    }
};
