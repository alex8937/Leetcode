class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cand;
        help(ans, cand, target, candidates, 0);
        return ans;
    }
    
    void help(vector<vector<int>>& ans, vector<int>& cand, int target, const vector<int>& nums, int start) {
        if(target == 0) {
            ans.push_back(cand);
        }
        for(int i = start; i < nums.size() && target > 0; ++i) {
            cand.push_back(nums[i]);
            help(ans, cand, target - nums[i], nums, i);
            cand.pop_back();
        }
    }
};