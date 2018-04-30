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
//Recursion
    bool isMatch(string s, string p) {
        return help(s, p, 0, 0);
    }
    bool help(string&s, string& p, int i, int j) {
        if (i == s.size() && j == p.size()) return true;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return i < s.size() && (s[i] == p[j] || p[j] == '.') && help(s, p, i + 1, j) || help(s, p, i, j + 2);
        }
        else {	
            return i < s.size() && j < p.size() && (s[i] == p[j] || p[j] == '.') && help(s, p, i + 1, j + 1);
        }
    }
};