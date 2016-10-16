class Solution {
public:
    bool isMatch(string s, string p) {
		// Dynamic programming
      vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
      dp[0][0] = true;
      for(int i = 2; i < dp.size(); ++i) {
          dp[i][0] =  dp[i - 2][0] && p[i - 1] == '*';
      }
      for(int i = 1; i < dp.size(); ++i) {
        for(int j = 1; j < dp[0].size(); ++j) {
          if(p[i - 1] != '*') {
            dp[i][j] = (p[i - 1] == '.' || p[i - 1] == s[j - 1]) && dp[i - 1][j - 1];  
          }
          else {
            dp[i][j] = dp[i - 2][j] || (dp[i][j - 1] && (p[i - 2] == s[j - 1] || p[i - 2] == '.'));  
          }
        }
      }
      return dp.back().back();
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
		// Recursion
        if(p.empty()) return s.empty();
        if(p[1] != '*') {
            return !s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        else {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        }
    }
};