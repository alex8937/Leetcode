class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        auto cur_cost = costs[0];
        for(int i = 1; i < costs.size(); ++i) {
            auto minCost = minExceptSelf(cur_cost);
            for(int j = 0; j < costs[0].size(); ++j) {
                cur_cost[j] = costs[i][j] + minCost[j];
            }
        }
        int ans = INT_MAX;
        for(auto c : cur_cost) ans = min(c, ans);
        return ans;
        
    }
    
    vector<int> minExceptSelf(vector<int>& nums) {
        auto ans = nums;
        for(int i = 1; i < int(nums.size()) - 1; ++i) {
            ans[i] = min(ans[i - 1], nums[i]);
        }      
        int right = nums.back();
        for(int i = int(nums.size()) - 1; i >= 0; --i) {
            if(i == int(nums.size()) - 1) ans[i] = ans[i - 1];
            else if(i == 0) ans[i] = right;
            else ans[i] = min(ans[i - 1], right);
            right = min(right, nums[i]);
        }
        return ans;
    }
};