class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> trusters;
        unordered_map<int, int> num_trusted;
        for(auto &v : trust){
            trusters[v[0]].push_back(v[1]);
            num_trusted[v[1]]++;
        }

        for(int i = 1; i < n+1; i++){
            if(trusters.find(i) == trusters.end() && num_trusted[i] == n-1){
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