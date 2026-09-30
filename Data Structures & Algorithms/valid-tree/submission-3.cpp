class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        q.push({0, -1});
        vector<int> visited(n, 0);
        visited[0] = 1;

        while(!q.empty()){
            auto p = q.front(); q.pop();
            int curr = p.first;
            int parent = p.second;

            for(int v : adjList[curr]){
                if(v == parent) {
                    continue;
                }
                if(visited[v]){
                    return false;
                }
                visited[v] = 1;
                q.push({v, curr});
                // if(v != parent && !visited[v]){
                //     q.push({v, curr});
                //     visited[v] = 1;
                // } else if (v != parent && visited[v]){
                //     return false;
                // }
            }
        }

        for(int i : visited){
            if(!i) return false;
        }

        return true;
    }

    // bool dfs(int i, unordered_set<int> &visit, unordered_map<int, vector<int>> &adjList, int p){
    //     if(visit.count(i)) return false;

    //     if(adjList[i].empty()){
    //         if(!disc.count(i)){
    //             visit.insert(i);
    //             disc.insert(i);
    //         }
    //         return true;
    //     }

    //     for(int v : adjList[i]){
    //         if(!dfs(v, visit, adjList)){
    //             return false;
    //         }
    //     }

    //     visit.erase(i);
    //     adjList[i].clear();
    //     disc.insert(i);
    //     return true;
    // }
};
