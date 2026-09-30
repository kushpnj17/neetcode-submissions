class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> edges(numCourses, 0);
        for(auto &v : prerequisites){
            edges[v[0]]++;
        }

        unordered_map<int, vector<int>> adj_list;
        for(auto &v : prerequisites){
            adj_list[v[1]].push_back(v[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(edges[i] == 0){
                q.push(i);
            }
        }

        int finished = 0;
        vector<int> vec;
        while(!q.empty()){
            int p = q.front(); q.pop();
            finished++;
            vec.push_back(p);

            for(int n : adj_list[p]){
                edges[n]--;
                if(!edges[n]){
                    q.push(n);
                }
            }
        }

        if(finished == numCourses){
            return vec;
        }

        return {};
    }
};
