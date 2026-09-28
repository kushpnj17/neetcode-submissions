class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto p = q.front(); q.pop();
            int row = p.first;
            int col = p.second;
            
            for(int k = 0; k < 4; k++){
                int r = row + x[k];
                int c = col + y[k];

                if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 2147483647){
                    grid[r][c] = grid[row][col]+1;
                    q.push({r,c});
                }
            }
        }
    }
};
