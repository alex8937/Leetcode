class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto right = upper_bound(nums.begin(), nums.end(), target)  - nums.begin() - 1;  
        if(left > right) return {-1, -1};
        return {left, right};
    }
};