class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        cache = {}
        def helper(triangle, i, j):
            if i == len(triangle):
                return 0
            if (i, j) not in cache:
                cache[(i, j)] = triangle[i][j] + min(helper(triangle, i + 1, j), helper(triangle, i + 1, j + 1))
            return cache[(i, j)]
        return helper(triangle, 0, 0)