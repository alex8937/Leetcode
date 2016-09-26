class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(exist(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, int i, int j, int index, string& word) {
        if(index == word.size()) return true;
        int row = board.size(), col = board[0].size();
        if(i < 0 || i >= row || j < 0 || j >= col) return false;
        if(board[i][j] != word[index]) return false;
        char temp = board[i][j];
        board[i][j] = '$';
        if(exist(board, i + 1, j, index + 1, word)) return true;
        if(exist(board, i - 1, j, index + 1, word)) return true;
        if(exist(board, i, j + 1, index + 1, word)) return true;
        if(exist(board, i, j - 1, index + 1, word)) return true;
        board[i][j] = temp;
        return false;
    }
};