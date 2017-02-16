
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

def maxArea2(height):
    """
    :type height: List[int]
    :rtype: int
    >>> maxArea2([1,2])
    1
    >>> maxArea2([1,2,4,5])
    4
    >>> maxArea2([5,2,4,5,2])
    15
    >>> maxArea2([1,6,4,2])
    4
    """
    area, start, end = 0, 0, len(height) - 1
    while start < end:
        area = max(area, min(height[start], height[end]) * (end - start))
        if height[start] <= height[end]:
            start += 1
        else:
            end -= 1
    return area
