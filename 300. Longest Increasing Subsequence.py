def lengthOfLIS(nums):
    """
    O(nlogn) algorithm
    >>> lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])
    4
    >>> lengthOfLIS([10, 11, 12, 13, 6, 7])
    4
    >>> lengthOfLIS([])
    0
    """

    helper = []
    for val in nums:
        index_last_less = findIndexLastLess(helper, val)
        if index_last_less == len(helper) - 1:
            helper.append(val)
        else:
            helper[index_last_less + 1] = val
    return len(helper)

def findIndexLastLess(helper, val):
    start, end = 0, len(helper) - 1
    while start < end:
        mid = start + (end - start) // 2 + 1
        if helper[mid] < val:
            start = mid
        else:
            end = mid - 1
    return start if helper and helper[start] < val else -1

def LIS(nums):
    """
    O(nlogn2) algorithm
    >>> LIS([10, 9, 2, 5, 3, 7, 101, 18])
    [2, 3, 7, 18]
    >>> LIS([10, 11, 12, 13, 6, 7])
    [10, 11, 12, 13]
    >>> LIS([])
    []
    """

    if not nums:
        return []
    helper, pre = [], [-1] * len(nums)
    for index, val in enumerate(nums):
        index_last_less = findIndexLastLess2(helper, val, nums)
        if index_last_less == len(helper) - 1:
            helper.append(index)
        else:
            helper[index_last_less + 1] = index
        if index_last_less >= 0:
            pre[index] = helper[index_last_less]
    ans, nxt = [nums[helper[-1]]], pre[helper[-1]]
    while nxt != -1:
        ans.append(nums[nxt])
        nxt = pre[nxt]
    return list(reversed(ans))

def findIndexLastLess2(helper, val, nums):
    start, end = 0, len(helper) - 1
    while start < end:
        mid = start + (end - start) // 2 + 1
        if nums[helper[mid]] < val:
            start = mid
        else:
            end = mid - 1
    return start if helper and nums[helper[start]] < val else -1
