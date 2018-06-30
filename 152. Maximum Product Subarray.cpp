class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int pos = nums[0], neg = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int pos_pre = pos, neg_pre = neg;
            pos = max(nums[i], max(pos_pre * nums[i], neg_pre * nums[i]));
            neg = min(nums[i], min(pos_pre * nums[i], neg_pre * nums[i]));
            ans = max(ans, pos);
        }
        return ans;
    }
};