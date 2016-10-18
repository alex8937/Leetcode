class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) i--; //3852
        reverse(nums.begin() + i, nums.end());//3258
        if (i > 0) {
            int target = i - 1;
            while (nums[i] <= nums[target] && i < nums.size()) i++;
            swap(nums[target], nums[i]);//3528
        }
    }
};