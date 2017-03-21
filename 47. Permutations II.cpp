class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cand;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        help(ans, cand, visited, nums);
        return ans;
    }
    void help(vector<vector<int>>& ans, vector<int>& cand, vector<bool>& visited, const vector<int>& nums) {
        if(cand.size() == nums.size()) {
            ans.push_back(cand);
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            cand.push_back(nums[i]);
            visited[i] = true;
            help(ans, cand, visited, nums);
            cand.pop_back();
            visited[i] = false;
        }
    }
};

