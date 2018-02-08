class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start, end = 0, len(nums) - 1
        while start < end:
            mid = start + (end - start) / 2
            if nums[mid] > nums[-1]:
                start = mid + 1
            else:
                end = mid
        return nums[start]