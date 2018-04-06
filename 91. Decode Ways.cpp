class Solution {
public:
    //version1: using addition
    int numDecodings(string s) {
        int ans = 0, pre = 1, ppre = 0;
        for(int i = 0; i < s.size(); ++i) {
            ans = 0;
            if(valid(s[i])) ans += pre;
            if(i > 0 && valid(s[i - 1], s[i])) ans += ppre;
            if(ans == 0) return 0;
            ppre = pre;
            pre = ans;
        }
        return ans;
    }
    // version2: using product
    int numDecodings(string s) {
      int ans = 0, pre = 1, ppre = 1;
      for (int i = 0; i < s.size(); i++) {
        if(i == 0) ans = pre * valid(s[i]);
        else ans = pre * valid(s[i]) + ppre * valid(s[i - 1], s[i]);
        if (ans == 0) return 0;
        ppre = pre;
        pre = ans;
      }
      return ans;
    }
    
    bool valid(char a) {
        return a != '0';
    }
    bool valid(char a, char b) {
        return a == '1' || (a == '2' && b <= '6');
    }
};