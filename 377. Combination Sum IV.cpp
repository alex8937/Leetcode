class Solution {
public:
// top down
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dict{{0, 1}};
        return helper(dict, nums, target);
    }
    int helper(unordered_map<int, int>& dict, vector<int>& nums, int target) {
        if(dict.count(target)) return dict[target];
        int ans = 0;
        for(int n : nums) {
            if(target - n >= 0) ans += helper(dict, nums, target - n);
        }
        dict[target] = ans;
        return ans;
    }
};


class Solution {
public:
// bottom up
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> ans(target + 1, 0);
        ans[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int n : nums) {
                if(i - n >= 0) ans[i] += ans[i - n];
            }
        }
        return ans.back();
    }
};
                        