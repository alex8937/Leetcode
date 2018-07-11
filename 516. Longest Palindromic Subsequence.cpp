class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> ans(s.size(), vector<int>(s.size(), 0));
        for(int end = 0; end < s.size(); ++end) {
            for(int start = end; start >= 0; --start) {
                if(s[start] == s[end]) {
                    ans[start][end] = (start == end? -1 : ans[start + 1][end - 1]) + 2;
                }
                else {
                    ans[start][end] = max(ans[start + 1][end], ans[start][end - 1]);
                }
            }
        }
        return ans[0].back();
    }
};