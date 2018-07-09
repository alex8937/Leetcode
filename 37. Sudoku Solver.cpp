class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), blk(9, 0);
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int val = 1 << (board[i][j] - '1');
                row[i] |= val;
                col[j] |= val;
                blk[i / 3 * 3 + j / 3] |= val;
            }
        }
        helper(board, 0, 0, row, col, blk);       
    }
    bool helper(vector<vector<char>>& board, int i, int j, vector<int>& row, vector<int>& col, vector<int>& blk) {
        if(i == 9) return true;
        if(j == 9) return helper(board, i + 1, 0, row, col, blk);
        if(board[i][j] != '.') return helper(board, i, j + 1, row, col, blk);
        for(int k = 1; k <= 9; ++k) {
            int mask = (1 << (k - 1));
            if(row[i] & mask) continue;
            if(col[j] & mask) continue;
            if(blk[i / 3 * 3 + j / 3] & mask) continue;
            row[i] |= mask;
            col[j] |= mask;
            blk[i / 3 * 3 + j / 3] |= mask;
            board[i][j] = k + '0';
            if(helper(board, i, j + 1, row, col, blk)) return true;
            row[i] &= ~mask;
            col[j] &= ~mask;
            blk[i / 3 * 3 + j / 3] &= ~mask;            
            board[i][j] = '.';
        }
        return false;
    }
    
};