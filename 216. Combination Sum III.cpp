class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cand;
        helper(ans, cand, k, n, 1);
        return ans;
    }
    
    void helper(vector<vector<int>>& ans, vector<int>& cand, int k, int n, int start) {
        if(cand.size() == k && n == 0) {
            ans.push_back(cand);
        }
        for(int i = start; i <= 9; ++i) {
            if(cand.size() == k || n - i < 0) break;
            cand.push_back(i);
            helper(ans, cand, k, n - i, i + 1);
            cand.pop_back();
        }
    }
};