class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prereqs(numCourses, 0);
        unordered_map<int, vector<int>> umap;
        for(auto &v : prerequisites){
            prereqs[v[1]]++;
            umap[v[0]].push_back(v[1]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(prereqs[i] == 0){
                q.push(i);
            }
        }

        int finished = 0;
        while(!q.empty()){
            int p = q.front(); q.pop();
            finished++;

            for(int n : umap[p]){
                prereqs[n]--;
                if(!prereqs[n]){
                    q.push(n);
                }
            }
        }

        return finished == numCourses;
    }
};
