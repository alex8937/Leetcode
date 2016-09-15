class Solution {
public
    bool isPowerOfThree(int n) {
			//version 1;
        if(n == 0) return false;
        if(n == 1) return true;
        return (n % 3 == 0) && isPowerOfThree(n / 3);
			//version 2:
				return n != 0 && pow(3, round(log(n) / log(3))) == n;
    }
};