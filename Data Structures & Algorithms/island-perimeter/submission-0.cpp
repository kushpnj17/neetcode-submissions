class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x = {-1,1,-0,0};
        vector<int> y = {0,0,-1,1};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int perimeter = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    grid[i][j] = 1;
                    visited[i][j] = 1;

                    while(!q.empty()){
                        auto p = q.front(); q.pop();
                        perimeter += 4;

                        for(int k = 0; k < 4; k++){
                            int r = x[k] + p.first;
                            int c = y[k] + p.second;
                            if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1){
                                perimeter--;
                                if(!visited[r][c]){
                                    visited[r][c] = 1;
                                    q.push({r,c});
                                }
                            }
                        }
                    }

                    return perimeter;
                }
            }
        }

        return 0;
    }
};