class Solution {
public
    int numDecodings(string s) {
        if(s.empty()) return 0;
        long ans = 1, pre = 1, ppre = 1, mod = pow(10, 9) + 7;
        for(int i = 0; i  s.size(); ++i) {
            if(i == 0) ans = pre  valid(s[i]);
            else ans = pre   valid(s[i]) + ppre  valid(s[i - 1], s[i]);
            if(ans == 0) return 0;
            ppre = pre % mod;
            pre = ans % mod;
        }
        return ans % mod;
    }
    
    int valid(char c) {
        return (c == '') 9  c  '0';
    }
    
    int valid(char a ,char b) {
        if(a == '' && b == '') return 15;
        if(isdigit(a) && isdigit(b)) return a == '1'  (a == '2' && b = '6');
        if(a == '') return (b = '6') 2  1;
        if(b == '') return (a == '1') 9  ((a == '2')  6  0);
    }  
};