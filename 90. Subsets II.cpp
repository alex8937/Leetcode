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
    	vector<vector<int>> sets;
    	vector<int> cand;
    	subset_helper(nums, sets, cand, 0);
    	return sets;
    }
    
    void subset_helper(const vector<int>& nums, vector<vector<int>>& sets, vector<int>& cand, int level){
    	sets.push_back(cand);
    	for(int i = level; i < nums.size(); ++i){
    		if(i - 1 >=0 && i!= level && nums[i] == nums[i - 1]) continue;
    		cand.push_back(nums[i]);
    		subset_helper(nums, sets, cand, i + 1);
    		cand.pop_back();
        }
    }
};