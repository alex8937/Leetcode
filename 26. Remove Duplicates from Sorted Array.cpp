class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int record = nums[0], tail = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != record) {
                record = nums[tail++] = nums[i];
            }
        }
        return tail;
        
    }
};