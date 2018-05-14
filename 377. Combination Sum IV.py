class Solution:
    def combinationSum4(self, nums, target):
    # top down
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        cache = {0 : 1}
        def helper(target):
            if target in cache:
                return cache[target]
            ans = 0
            for num in nums:
                if target - num >= 0:
                    ans += helper(target - num)
            cache[target] = ans
            return ans
        return helper(target)
        
class Solution:
    def combinationSum4(self, nums, target):
    # bottom up
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        ans = [0] * (target + 1)
        ans[0] = 1
        for i in range(1, len(ans)):
            for num in nums:
                if i - num < 0: continue
                ans[i] += ans[i - num]
        return ans[-1]
                        