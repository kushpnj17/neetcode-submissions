class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};
        queue<pair<int,int>> q;

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'Y';
                q.push({0,j});
            }

            if(board[n-1][j] == 'O'){
                board[n-1][j] = 'Y';
                q.push({n-1, j});
            }
        }

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'Y';
                q.push({i,0});
            }

            if(board[i][m-1] == 'O'){
                board[i][m-1] = 'Y';
                q.push({i,m-1});
            }
        }

        while(!q.empty()){
            auto p = q.front(); q.pop();
            
            for(int k = 0; k < 4; k++){
                int r = p.first + x[k];
                int c = p.second + y[k];
                if(r>=0 && r<n && c>=0 && c<m && board[r][c] == 'O'){
                    board[r][c] = 'Y';
                    q.push({r,c});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
