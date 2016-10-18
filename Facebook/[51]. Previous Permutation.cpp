class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int i = nums.size() - 1;  
        while (i > 0 && nums[i] >= nums[i - 1]) {  
            i--;  
        } // 5238
        reverse(nums.begin() + i, nums.end()); // 5832
        if (i > 0) {  
            int target = i - 1;  
            while (i < nums.size() && nums[i] >= nums[target]) {  
                i++;  
            }  
            swap(nums[target], nums[i]);  //3852
        }               
        return nums;
    }
};