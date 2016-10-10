class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> ans(obstacleGrid[0].size(), 0);
        ans[0] = 1 - obstacleGrid[0][0];
        for(int i = 0; i < obstacleGrid.size(); ++i) {
            for(int j = 0; j < obstacleGrid[0].size(); ++j) {
                if(obstacleGrid[i][j] == 1) ans[j] = 0;
                else ans[j] += (j >= 1)? ans[j - 1] : 0;
            }
        }
        return ans.back();
        
    }
};