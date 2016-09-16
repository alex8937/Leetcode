class Solution {
public:
    int climbStairs(int n) {
        int low = 1;
        int high = 1;
        int ans = low;
        for(int i = 2; i <= n; ++i) {
            ans = high + low;
            low = high;
            high = ans;
        }
        return ans;
        
    }
};