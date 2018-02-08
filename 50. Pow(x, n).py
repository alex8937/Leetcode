class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if not n:
            return 1.0
        if n < 0:
            return 1 / self.myPow(x, -n) 
        half = self.myPow(x, n // 2)
        return half * half * x if n % 2 else half * half