"""
Use Linear Diophantine equations:
Given x, y, z, then nx + my = z has integer solution of m, n
if only if z % gcd(x, y) == 0

The way to find gcd: Euclidean algorithm

Edge case:
1. if container z == 0, then always succeeds
2. if z > x + y, then alway fails
"""
class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        return z == 0 or x + y >= z and z % gcd(x, y) == 0 
	
	@staticmethod
	def gcd(x, y):
		if y == 0:
			return x 
		else:
			return gcd(y, x % y)
