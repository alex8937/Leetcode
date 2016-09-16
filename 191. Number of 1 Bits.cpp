class Solution {
public:
    int hammingWeight(uint32_t n) {
    // version 1:
        int ans = 0;
        while(n) {
            if((n & 1) == 1) {
                ans++;
            }
            n >>= 1;
        }
        return ans;
    // version 2:
        int ans = 0;
        while(n) {
            n &= (n - 1);
            ans++;
        }
        return ans;
    }
};