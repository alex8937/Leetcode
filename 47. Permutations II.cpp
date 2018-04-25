class Solution {
public:
// Using visit bool vector
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

class Solution {
public:
// Using Swap: Notice nums needed to be copy instead of reference
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        help(ans, nums, 0);
        return ans;
    }
    
    void help(vector<vector<int>>& ans, vector<int> nums, int k) {
        if(k == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = k; i < nums.size(); ++i) {
            if(i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            help(ans, nums, k + 1);
        }
    }
};
