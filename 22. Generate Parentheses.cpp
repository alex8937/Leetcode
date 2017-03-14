class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(ans, "", 0, 0, n);
        return ans;
    }
    void help(vector<string>& ans, string cand, int left, int right, const int& n) {
        if(left == n && right == n) {
            ans.push_back(cand);
            return;
        }
        if(left < n) help(ans, cand + '(', left + 1, right, n);
        if(right < left) help(ans, cand + ')', left, right + 1, n);
    }
};