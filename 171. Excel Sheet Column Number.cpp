class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int base = 1;
        for(int i = s.size() - 1; i >= 0; --i) {
            int digit = s[i] - 'A' + 1;
            sum += base * digit;
            base *= 26;
        }
        return sum;
    }
};