class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //version1: math
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for(int n : nums) {
            sum -= n;
        }
        return sum;
    //version2: bit manipulation 
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            ans ^= (i + 1) ^ nums[i];
        }
        return ans;
    }
};