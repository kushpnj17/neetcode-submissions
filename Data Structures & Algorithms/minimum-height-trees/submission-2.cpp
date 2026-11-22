class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int, vector<int>> adjlist;
        for(auto v : edges){
            adjlist[v[0]].push_back(v[1]);
            adjlist[v[1]].push_back(v[0]);
        }

        vector<vector<int>> heights(n);
        int min_height = INT_MAX;
        for(int i = 0; i < n; i++){
            int h = find_height(i, adjlist);
            cout << "h: " << h << endl;
            cout << "root: " << i << endl;
            cout << endl;
            heights[h].push_back(i);
            min_height = min(min_height, h);
        }

        return heights[min_height];
    }

    int find_height(int root, unordered_map<int, vector<int>> &adjlist){
        queue<int> q;
        unordered_set<int> visited;
        q.push(root);
        visited.insert(root);
        int h = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int p = q.front(); q.pop();

                for(int n : adjlist[p]){
                    if(!visited.count(n)){
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }

            h++;
        }

        return h-1;
    }
};