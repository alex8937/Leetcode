class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int first_val = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                swap(nums[i], nums[first_val++]);
            }
        }
        nums.erase(nums.begin() + first_val, nums.end());
        return nums.size();
    }
};