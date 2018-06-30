class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int ans[3] = {0};
        for(auto cost : costs) {
            auto ans_pre = new int(ans);
            ans[0] = cost[0] + min(ans_pre[1], ans_pre[2]);
            ans[1] = cost[1] + min(ans_pre[0], ans_pre[2]);
            ans[2] = cost[2] + min(ans_pre[0], ans_pre[1]);
        }
        return min(ans[0], min(ans[1], ans[2]));
    }
};