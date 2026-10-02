class Solution {
    vector<bool> res;
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, unordered_set<int>> prereqs;
    vector<int> indegree;
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        indegree.resize(numCourses, 0);
        for(auto &v : prerequisites){
            adjList[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }

        kahn();
        for(auto &v : queries){
            if(prereqs[v[1]].count(v[0])){
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }

    void kahn(){
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                prereqs[i] = {};
                q.push(i);
            }
        }

        while(!q.empty()){
            int p = q.front(); q.pop();

            for(int n : adjList[p]){
                prereqs[n].insert(p);
                prereqs[n].insert(prereqs[p].begin(), prereqs[p].end());
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }
    }
};