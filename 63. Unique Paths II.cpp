class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<int> ans(col, 0);
        ans[0] = 1 - obstacleGrid[0][0];
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(i == 0 && j == 0)  continue;
                if(obstacleGrid[i][j]) {
                    ans[j] = 0;
                }
                else{
                    int cand1 = (i > 0 && !obstacleGrid[i - 1][j])? ans[j] : 0;
                    int cand2 = (j > 0 && !obstacleGrid[i][j - 1])? ans[j - 1] : 0;
                    ans[j] = cand1 + cand2;
                }
            }
        }
        return ans.back();
    }
};