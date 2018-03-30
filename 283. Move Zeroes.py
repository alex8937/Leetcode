def move_zeroes(nums):
    """
    >>> move_zeroes([0, 3, 0, 2, 1])
    [3, 2, 1, 0, 0]
    >>> move_zeroes([3, 0, 0, 2, 1])
    [3, 2, 1, 0, 0]
    """
    first_zero = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[i], nums[first_zero] = nums[first_zero], nums[i]
            first_zero += 1
    return nums
    
def move_zeroes2(nums):
    """
    >>> move_zeroes([0, 3, 0, 2, 1])
    [3, 2, 1, 0, 0]
    >>> move_zeroes([3, 0, 0, 2, 1])
    [3, 2, 1, 0, 0]
    """
    last = 0
    for i in range(len(nums)):
      if nums[i] != 0:
        nums[pos] = nums[i]
        pos += 1
    return nums
    
    
    
    
    
    
    
    
    
    
    
    
    
