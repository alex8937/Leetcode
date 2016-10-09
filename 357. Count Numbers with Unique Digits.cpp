class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 0, cur = 0;
        for(int i = 0; i <= n; ++i) {
            if(i == 0) cur = 1;
            else if(i == 1 || i == 2) cur = cur * 9;
            else cur = cur * (11 - i);
            sum += cur;
        }
        return sum;
    }
};