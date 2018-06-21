class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int yes0 = 0, no0 = 0, yes1 = 0, no1 = 0;
        for(int i = 1; i < nums.size(); ++i) { // either the first house is not robbed
            int yes_pre0 = yes0;
            yes0 = no0 + nums[i];
            no0 = max(yes_pre0, no0);
        }
        for(int i = 0; i < int(nums.size()) - 1; ++i) { // or the last one is not robbed
            int yes_pre1 = yes1;
            yes1 = no1 + nums[i];
            no1 = max(yes_pre1, no1);
        }        
        return max(max(yes1, no1), max(yes0, no0));
    }
};