class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(nums, start, end):
            if start == end:
                return nums[start], nums[start], nums[start], nums[start]
            mid = (start + end) // 2
            left = helper(nums, start, mid)
            right = helper(nums, mid + 1, end)
            start_left = max(left[0], left[3] + right[0])
            end_right = max(right[1], left[1] + right[3])
            whole_max = max(left[2], right[2], left[1] + right[0])
            whole_sum = left[3] + right[3]
            return start_left, end_right, whole_max, whole_sum
    
        return helper(nums, 0, len(nums) - 1)[2]
            