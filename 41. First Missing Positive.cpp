class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
			// O(n) algorithm: each swap put one element in the right position;
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {  // Note: it should be while
                swap(nums[i], nums[nums[i] - 1]); // Put in the right position
            }
        }
        int i = 0;
        for(; i < nums.size(); ++i) {
            if(nums[i] != i + 1) break;
        }
        return i + 1;
    }
};