class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,-1,1};
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    queue<pair<int,int>> q;
                    grid[i][j] = '0';
                    q.push({i,j});
                    count++;

                    while(!q.empty()){
                        auto p = q.front(); q.pop();

                        for(int k = 0; k < 4; k++){
                            int r = p.first + x[k];
                            int c = p.second + y[k];

                            if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                q.push({r,c});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
