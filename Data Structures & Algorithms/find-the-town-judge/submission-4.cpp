class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        for(auto &v : trust){
            indegree[v[1]]++;
            outdegree[v[0]]++;
        }

        for(int i = 1; i < n+1; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i;
            }
        }

        return -1;
    }
};

// adjList
// 1: 2
// 2: 1,3
// 3: 
// 4: 1,2

// adjList
// 1: 3
// 2: 3
// 3: 1,2