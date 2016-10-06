class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> block(9, 0);
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != '.') {
                    int num = 1 << (board[i][j] - '1');
                    if((row[i] & num) || (col[j] & num) || (block[i / 3 * 3 + j / 3] & num)) return false;
                    row[i] |= num;
                    col[j] |= num;
                    block[i / 3 * 3 + j / 3] |= num;
                }
            }
        }
        return true;
        
    }
};