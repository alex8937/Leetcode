class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        >>> s = Solution()
        >>> s.decodeString('fa3[b2[d]]e')
        'fabddbddbdde'
        """
        repeat_starts, ret, times = [], '', 0
        for c in s:
            if c == '[':
                repeat_starts.append((times, len(ret)))
                times = 0
            elif c == ']':
                pair = repeat_starts.pop()
                ret += (pair[0] - 1) * ret[pair[1] :]
            elif c.isdigit():
                times = times * 10 + int(c)
            else:
                ret += c
        return ret

if __name__ == "__main__":
    import doctest
    doctest.testmod()
