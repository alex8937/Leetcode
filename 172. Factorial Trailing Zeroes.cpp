class Solution {
public:
    int trailingZeroes(int n) {
        long long base = 5;
        int ans = 0;
        while(base <= n) {
            ans += n / base;
            base *= 5;
        }
        return ans;
    }
};