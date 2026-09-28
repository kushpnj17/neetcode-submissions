class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        while(!q.empty() && fresh){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto p = q.front(); q.pop();

                for(int k = 0; k < 4; k++){
                    int r = p.first + x[k];
                    int c = p.second + y[k];

                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1){
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r,c});
                    }
                }
            }

            minutes++;
        }

        if(fresh > 0) return -1;

        return minutes;
    }
};
