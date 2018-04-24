class Solution {
public:
// ver1: Use visited vector
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cand;
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
// ver2: Use Swap
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(ans, nums, 0);
        return ans;
    }
    
    void help(vector<vector<int>>& ans, vector<int>& nums, int k) {
        if(k == nums.size()) ans.push_back(nums);
        for(int i = k; i < nums.size(); ++i) {
            swap(nums[i], nums[k]);
            help(ans, nums, k + 1);
            swap(nums[i], nums[k]);
        }
    }
};