class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cand;
        sort(candidates.begin(), candidates.end());
        help(ans, cand, target, candidates, 0);
        return ans;
    }
    
    void help(vector<vector<int>>& ans, vector<int>& cand, int target, const vector<int>& nums, int start) {
        if(target == 0) {
            ans.push_back(cand);
        }
        for(int i = start; i < nums.size() && target > 0; ++i) {
            if(i > start && nums[i] == nums[i - 1]) continue;
            cand.push_back(nums[i]);
            help(ans, cand, target - nums[i], nums, i + 1);
            cand.pop_back();
        }
    }
};