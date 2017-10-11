class Solution:
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = list(str(num))
        shift_index = self.findShiftIndex(num)
        if shift_index != -1:
            large_index = self.findLargeIndex(num, shift_index)
            small_index = self.findSmallIndex(num, shift_index, large_index)
            num[large_index], num[small_index] = num[small_index], num[large_index]

        return int(''.join(num))

    def findShiftIndex(self, num):
        for index in range(1, len(num)):
            if num[index - 1] < num[index]:
                return index
        return -1

    def findLargeIndex(self, num, shift_index):
        pos = shift_index
        for index in range(shift_index + 1, len(num)):
            if num[index] >=  num[pos]:
                pos = index
        return pos

    def findSmallIndex(self, num, shift_index, large_index):
        for pos in range(shift_index):
            if num[pos] < num[large_index]:
                return pos
        return -1
