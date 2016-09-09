class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int c = a & b;
            a = a ^ b;
            b = (c << 1);
        }
        return a;
    }
};

// Explanation: a & b gives all digits need to be carried
// a ^ b gives the rest