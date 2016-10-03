class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == '1') {
                    if(i > 0 && j > 0) {
                        matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j])) + 1;
                    }
                    ans = max(ans, matrix[i][j] - '0');
                }
            }
        }
        return ans * ans;
    }
};