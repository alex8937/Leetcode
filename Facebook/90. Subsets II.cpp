class Solution {
public:
// Iteration:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> ans(1, vector<int>());
      sort(nums.begin(), nums.end());
      int len = ans.size();
      for(int i = 0; i < nums.size(); ++i) {
        int start = (i > 0 && nums[i] == nums[i - 1])? len : 0;
        len = ans.size();
        for(int j = start; j < len; ++j) {
          ans.push_back(ans[j]);
          ans.back().push_back(nums[i]);
        }
      }
      return ans;  
    }
};

class Solution {
public:
// Recursion:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> ans;
    	vector<int> cand;
    	subset_helper(ans, cand, 0, nums);
    	return ans;
    }
    
    void subset_helper(vector<vector<int>>& ans, vector<int>& cand, int level, const vector<int>& nums){
    	ans.push_back(cand);
    	for(int i = level; i < nums.size(); ++i){
    		if(i > level && nums[i] == nums[i - 1]) continue;
    		cand.push_back(nums[i]);
    		subset_helper(ans, cand, i + 1, nums);
    		cand.pop_back();
        }
    }
};