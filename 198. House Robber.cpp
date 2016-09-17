class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> sum = nums;
        for(int i = 2; i < len; ++i) {
            if(i == 2) sum[i] = nums[i] + nums[i - 2];
            else sum[i] = max(sum[i - 2], sum[i - 3]) + nums[i];
        }
        return max(sum[len - 1], sum[len - 2]);
        
    }
};