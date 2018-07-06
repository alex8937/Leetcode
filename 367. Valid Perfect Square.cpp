class Solution {
public:
    bool isPerfectSquare(int num) {
        int cand = round(find_sqrt(num));
        return cand * cand == num;
    }
    
    float find_sqrt(int nums) {
        float eps = 1e-3;
        float x_old = -1, x_new = nums;
        while(abs(x_new - x_old) > eps) {
            x_old = x_new;
            x_new = (x_old + nums / x_old) / 2;
        }
        return x_new;
    }
};