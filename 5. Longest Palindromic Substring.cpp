class Solution {
public:
    string longestPalindrome(string s) {
        int longest_start = 0, longest_end = 0;
        vector<vector<bool>> ans(s.size(), vector<bool>(s.size(), 0));
        for(int end = 0; end < s.size(); ++end) {
            for(int start = end; start >= 0; --start) {
                if(s[start] == s[end] && (end - start <= 1 || ans[start + 1][end - 1])) {
                    ans[start][end] = true;
                    if(longest_end - longest_start < end - start) {
                        longest_end = end;
                        longest_start = start;
                    }                    
                }
            }
        }
        return s.substr(longest_start, longest_end - longest_start + 1);
    }
};