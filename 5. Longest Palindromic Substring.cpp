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



class Solution {
public:
    string longestPalindrome(string s) {
        int best_start = 0, best_end = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int k = 0; k <= 1; ++k) {
                int j = 1;
                while(i + j < s.size() && i - j + k >= 0 && s[i - j + k] == s[i + j]) j++;
                if(2 * j - k - 2 > best_end - best_start) {
                    best_end = i + j - 1;
                    best_start = i - j + 1 + k;
                } 
            }
 
        }
        return s.substr(best_start, best_end - best_start + 1);
    }
};