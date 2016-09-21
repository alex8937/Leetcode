class Solution {
public:
    int mySqrt(int x) {
    //version2: Bisection Method
        int start = 0, end = x;
        while(start + 1 < end) {
            long mid = start + (end - start) / 2;
            if(mid * mid > x) {
                end = mid;
            }
            else if(mid * mid < x) {
                start = mid;
            }
            else {
                return mid;
            }
        }
        if(end * end - x == 0) return end;
        return start; 
    //version2: Newton's Method
        long ans = x;
        while(ans * ans > x) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};