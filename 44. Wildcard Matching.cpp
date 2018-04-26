class Solution {
public:
// LTE: Recurrsion
    bool isMatch(string s, string p) {
        return valid(s, p, 0, 0);
    }
    bool valid(string& s, string& p, int i, int j) {
        if(i == s.size() && j == p.size()) return true;
        if(j < p.size() && (s[i] == p[j] || p[j] == '?')) {
            return valid(s, p, i + 1, j + 1);
        } 
        else if(j < p.size() && p[j] == '*'){
            while(j + 1 < p.size() && p[j + 1] == '*') j++;
            bool ans = false;
            for(int k = i; k <= s.size(); ++k) {
                ans |= valid(s, p, k, j + 1);
                if(ans) return true;
            }
            return false;
        }
        return false;
    }
};


class Solution {
public:
// 2D matrix dynamic programming
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<bool>> dp(n, vector<bool>(m, false));
        dp[0][0] = true;
        int i = 1;
        while(i < n && p[i - 1] == '*') dp[i++][0]= true;
        for(int j = 1; j < m; ++j) {
            for(int i = 1; i < n; ++i) {
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                if(p[i - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};

class Solution {
public:
// Dynamic programming reduces to 1D space complexity
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<bool> dp(n, false);
        dp[0] = true;
        int i = 1;
        while(i < n && p[i - 1] == '*') dp[i++] = true;
        for(int j = 1; j < m; ++j) {
            vector<bool> temp(n, false);
            for(int i = 1; i < n; ++i) {
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?') temp[i] = dp[i - 1];
                if(p[i - 1] == '*') temp[i] = temp[i - 1] || dp[i];
            }
            temp.swap(dp);
        }
        return dp.back();
    }
};

class Solution {
public:
//Iterative Method
    bool isMatch(string s, string p) {
        int si = 0, pi = 0, sstar = -1, pstar = -1;
        while(si < s.size()) {
            if(pi < p.size() && (p[pi] == '?' || p[pi] == s[si])) {
                si++;
                pi++;
            }
            else if(pi < p.size() && p[pi] == '*') {
                pstar = pi;
                sstar = si;
                pi++;
            }
            else if(pstar != -1) {
                pi = pstar + 1;                   
                sstar++;
                si = sstar;             
            }
            else return false;   
        }
        while(pi < p.size() && p[pi] == '*') pi++;
        return pi == p.size();
    }
};