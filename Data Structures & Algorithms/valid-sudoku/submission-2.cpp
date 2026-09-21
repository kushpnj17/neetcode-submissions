class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '.') continue;

                int num = board[i][j];
                int k = (i/3)*3 + j/3;

                if(rows[i].find(num) != rows[i].end() ||
                   cols[j].find(num) != cols[j].end() ||
                   boxes[k].find(num) != boxes[k].end()){
                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                boxes[k].insert(num);
            }
        }

        return true;
    }
};

// 0: (0,0) (0,1) (0,2) (1,0) (1,1) (1,2) (2,0) (2,1) (2,2)

// (i/3)*3 + j/3
// i: 0, j: 0 = 0
// i: 8, j: 8 = 8
// i: 5, j: 5 = 4

