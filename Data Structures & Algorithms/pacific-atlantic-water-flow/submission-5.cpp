class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            pacific[i][0] = 1;
            pq.push({i,0});

            atlantic[i][m-1] = 1;
            aq.push({i, m-1});
        }

        for(int j = 0; j < m; j++){
            if(!pacific[0][j]){
                pacific[0][j] = 1;
                pq.push({0,j});
            }

            if(!atlantic[n-1][j]){
                atlantic[n-1][j] = 1;
                aq.push({n-1,j});
            }
        }

        bfs(heights, pacific, pq);
        bfs(heights, atlantic, aq);

        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<int>> &v, queue<pair<int,int>> &q){
        int n = heights.size();
        int m = heights[0].size();
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};
        while(!q.empty()){
            auto p = q.front(); q.pop();
            
            for(int k = 0; k < 4; k++){
                int r = p.first + x[k];
                int c = p.second + y[k];

                if(r>=0 && r<n && c>=0 && c<m && !v[r][c] && heights[r][c] >= heights[p.first][p.second]){
                    v[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
    }
};
