class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < int(nums.size()) - 2; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[start++], nums[end--]});
                }
                else if(sum < 0) {
                    start++;
                }
                else {
                    end--;

                }
                while(sum <= 0 && start < end && nums[start] == nums[start - 1]) start++; // skip duplicated nums[start]
                while(sum >= 0 && start < end && nums[end] == nums[end + 1]) end--; // skip duplicated nums[end]
            }
        }
        return ans;
    }
};