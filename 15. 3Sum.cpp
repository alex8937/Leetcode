class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicated nums[i]
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end) {
                if(nums[start] + nums[end] > -nums[i]) {
                    end--;
                }
                else if(nums[start] + nums[end] < -nums[i]){
                    start++;
                }
                else {
                    ans.push_back(vector<int>{nums[i], nums[start++], nums[end--]});
                    while(start < end && nums[start] == nums[start - 1]) start++; // skip duplicated nums[start]
                    while(start < end && nums[end] == nums[end + 1]) end--; // skip duplicated nums[end]
                }
            }
        }
        return ans;
    }
};