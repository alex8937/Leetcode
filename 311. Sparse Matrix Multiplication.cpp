class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row = A.size(), col = B[0].size(), inner = A[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < inner; ++j) {
                if(!A[i][j]) continue;
                for(int k = 0; k < col; ++k) {
                    if(B[j][k]) ans[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return ans;
    }
};