class Solution {
  // DP solution
public:
    int minCut(string s) {
        vector<int> ans(s.size() + 1, INT_MAX);
        ans[0] = -1;
        auto dict = valid(s);
        for(int i = 1; i < ans.size(); ++i) {
            for(int cur = 0; cur < i; ++cur) {
                if(dict[cur][i - 1]) ans[i] = min(ans[i], ans[cur] + 1);
            }
        }
        return ans.back();
    }
    
    vector<vector<bool>> valid(string& s) {
        vector<vector<bool>> dict(s.size(), vector<bool>(s.size(), false));
        for(int end = 0; end < s.size(); ++end) {
            for(int start = end; start >= 0; --start) {
                dict[start][end] = (s[start] == s[end]) && (end - start <= 1 || dict[start + 1][end - 1]);
            }
        }
        return dict;
    }
}

class Solution {
  //Manancher-like solution
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};