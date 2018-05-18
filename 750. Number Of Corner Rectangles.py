class Solution:
    def countCornerRectangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from functools import reduce
        grid = [reduce(lambda x, y : (x << 1) | y, row) for row in grid]
        ans = 0
        def count_ones(n):
            cnt = 0
            while n:
                n = n & (n - 1)
                cnt += 1
            return cnt
        for i in range(len(grid)):
            for j in range(i):    
                over_lap = count_ones(grid[i] & grid[j])
                ans += over_lap * (over_lap - 1) // 2
        return ans
                
       