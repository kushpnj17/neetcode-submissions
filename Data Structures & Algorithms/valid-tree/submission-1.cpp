class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        
        unordered_map<int, vector<int>> adj_list;
        for(auto v : edges){
            adj_list[v[0]].push_back(v[1]);
            adj_list[v[1]].push_back(v[0]);
        }

        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int count = 0;

        while(!q.empty()){
            int p = q.front(); q.pop();
            count++;

            for(int k : adj_list[p]){
                if(!visited[k]){
                    q.push(k);
                    visited[k] = 1;
                }
            }
        }

        return count == n;
    }
};
