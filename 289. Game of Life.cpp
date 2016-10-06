class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                int live = 0;
                for(int k = 0; k < 8; ++k) {
                    if(i + y[k] < 0 || i + y[k] >= row || j + x[k] < 0 || j + x[k] >= col) continue;
                    live += board[i + y[k]][j + x[k]] % 2;
                }
                if(board[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 3;
                else if(board[i][j] == 0 && live == 3) board[i][j] = 2;
            }
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == 3) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
            }
        }
        
    }
};