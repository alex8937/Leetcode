class Solution:
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        sums = [[(-math.inf, 0, 0) for _ in range(len(nums))] for _ in range(3)]
        for i in range(3):
            subsum = 0
            for j in range(i * k, len(nums) - k * (3 - i) + 1):
                if j == i * k:
                    subsum = sum(nums[j : j + k])
                else:
                    subsum = subsum - nums[j - 1] + nums[j + k - 1]
                if sums[i][j - 1][0] <  subsum + (sums[i - 1][j - k][0] if i > 0 else 0):
                    sums[i][j] = (subsum + (sums[i - 1][j - k][0] if i > 0 else 0), i - 1, j - k)
                else:
                    sums[i][j] = (sums[i][j - 1][0], i, j - 1)
       
        ans, row, col = [], 2, len(nums) - k
        while row >= 0:
            if sums[row][col][1] < row:
                ans.append(col)
            row, col = sums[row][col][1], sums[row][col][2]
        return ans[::-1]
            