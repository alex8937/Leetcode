class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long valid_sum = 1; // sum that can be reach
        int add = 0, pos = 0;
        while(valid_sum <= n) {
            if(pos >= nums.size() || nums[pos] > valid_sum) { // run out of array or current number larger than target sum 
                valid_sum <<= 1;        // add a target sum;
                add++;

            }
            else {              
                valid_sum += nums[pos];
                pos++;
            }
        }
        return add;
    }
};