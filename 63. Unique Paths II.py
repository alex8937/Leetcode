class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        n, m = len(obstacleGrid) + 1, len(obstacleGrid[0]) + 1
        ans = [[0] * m for _ in range(n)] 
        ans[1][1] = 1 - obstacleGrid[0][0]
        for i in range(1, n):
            for j in range(1, m):
                if obstacleGrid[i - 1][j - 1] or (i == 1 and j == 1):
                    continue
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1]
        return ans[-1][-1]
        