class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        jumps = {stone : set() for stone in stones}
        jumps[stones[0]].add(1)
        for stone in stones:
            for step in jumps[stone]:
                if stone + step in jumps:
                    jumps[stone + step].add(step + 1)
                    jumps[stone + step].add(step)
                    if step > 1:
                        jumps[stone + step].add(step - 1)
        return len(jumps[stones[-1]]) != 0