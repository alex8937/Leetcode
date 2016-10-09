class Solution {
public:
    int findNthDigit(int n) {
        long base = 1, digits = 1;
        while(n - base * 9 * digits > 0) {
            n -= base * 9 * digits;
            base *= 10;
            digits++;
        }
        int index = (n - 1) / digits + base;
        int offset = digits - (n - 1) % digits;
        while(offset > 1) {
            index /= 10;
            offset--;
        }
        return index % 10;
    }
};