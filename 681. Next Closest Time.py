class Solution:
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        ret_time = list(time)
        nums = sorted(list(set([time[0], time[1], time[3], time[4]])))
        def validTime(pos, ret_time, nums, index):
            num = nums[index + 1]
            return { 4 : int(ret_time[3] + num) >= 60,
                     3 : int(num + ret_time[4]) >= 60,
                     1 : int(ret_time[0] + num) >= 24,
                     0 : int(num + ret_time[1]) >= 24
                    }[pos]
        for pos in [4, 3, 1, 0]:
            for index, num in enumerate(nums):
                if ret_time[pos] == num:
                    if index + 1 >= len(nums) or validTime(pos, ret_time, nums, index):
                        ret_time[pos] = nums[0]
                    else:
                        ret_time[pos] = nums[index + 1]
                        return ''.join(ret_time)
        return ''.join(ret_time)
