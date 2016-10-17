class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; ++i) {
            ans = findnext(ans);
        }
        return ans;
    }
    
    string findnext(string s) {
        int end = 0;
        string ans;
        while(end < s.size()) {
            char record = s[end++];
            int len = 1;
            while(end < s.size() && s[end] == s[end - 1]) {
                end++;
                len++;
            }
            ans += to_string(len) + record;
        }
        return ans;
    }
};