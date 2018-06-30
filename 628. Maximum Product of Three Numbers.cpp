class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3, min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for(int n : nums) {
            if(n > max3) max3 = n;
            if(max3 > max2) swap(max3, max2);
            if(max2 > max1) swap(max2, max1);
            if(n < min2) min2 = n;
            if(min2 < min1) swap(min2, min1);            
        }
        return max(max1 * max2 *  max3, min1 * min2 * max1);
    }
};