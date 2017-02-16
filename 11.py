
def maxArea(height):
    """
    :type height: List[int]
    :rtype: int
    >>> maxArea([1,2])
    1
    >>> maxArea([1,2,4,5])
    4
    >>> maxArea([5,2,4,5,2])
    15
    >>> maxArea([1,6,4,2])
    4
    """
    area, start, end = 0, 0, len(height) - 1
    while start < end:
        h = min(height[start], height[end])
        area = max(area, h * (end - start))
        while start < end and height[start] <= h:
            start += 1
        while start < end and height[end] <= h:
            end -= 1
    return area
