class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cand;
        help(ans, cand, n, k, 1);
        return ans;
    }
    void help(vector<vector<int>>& ans, vector<int>& cand, const int& end, const int& count, int start) {
        if(cand.size() == count) {
            ans.push_back(cand);
        }
        for(int i = start; i <= end; ++i) {
            cand.push_back(i);
            help(ans, cand, end, count, i + 1);
            cand.pop_back();
        }
    }
};