class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area, left, right = 0, 0, len(height) - 1
        max_left = max_right = 0
        while left < right:
            if height[left] < height[right]:
                max_left = max(max_left, height[left])
                area += max_left - height[left]
                left += 1
            else:
                max_right = max(max_right, height[right])
                area += max_right - height[right]
                right -= 1
        return area
