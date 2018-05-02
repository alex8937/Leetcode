class Solution {
public:
    string minWindow(string S, string T) {
      int m = S.size() + 1, n = T.size() + 1;
      vector<int> ans(m, 0);
      for (int j = 1; j < n; ++j) {
        vector<int> temp(m, 0);
        for (int i = 1; i < m; ++i) {
          if (S[i - 1] == T[j - 1] && ans[i - 1] >= j - 1) temp[i] = ans[i - 1] + 1;
          else if(temp[i - 1] > 0)  temp[i] = temp[i - 1] + 1;
        }
        if (temp.back() == 0) return "";
        ans.swap(temp);
      }
      int end = S.size(), len = S.size();
      for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] > 0 && ans[i] < len) {
          len = ans[i];
          end = i;
        }
      }
      return S.substr(end - len, len);
    }
};