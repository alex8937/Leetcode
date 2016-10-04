class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        int same = 0, diff = k;
        for(int i = 2; i <= n; ++i) {
            int sum = same + diff;
            same = diff;
            diff = sum * (k - 1);
        }
        return same + diff;
    }
};