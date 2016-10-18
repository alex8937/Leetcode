class Solution {
public:
    string addBinary(string a, string b) {
      int i = a.size() - 1, j = b.size() - 1;
      string ans;
      int carry = 0;
      while(i >= 0 || j >= 0 || carry) {
        int n1 = (i >= 0)? (a[i--] - '0') : 0;
        int n2 = (j >= 0)? (b[j--] - '0') : 0;
        int val = n1 + n2 + carry;
        ans.push_back(val % 2 + '0');
        carry = val / 2;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};