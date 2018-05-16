class Solution {
public:
    string convertToTitle(int n) {
      string ans;
      while(n) {
        ans.push_back((n - 1) % 26 + 'A');
        n = (n - 1) / 26;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};