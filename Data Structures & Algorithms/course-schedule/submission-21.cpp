class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adjlist;
        for(auto v : prerequisites){
            adjlist[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        queue<int> q;
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }

        while(!q.empty()){
            int p = q.front(); q.pop();
            
            for(int i : adjlist[p]){
                indegree[i]--;
                if(!visited[i] && indegree[i] == 0){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }

        for(int i : indegree){
            if(i>0) return false;
        }

        return true;
    }
};
