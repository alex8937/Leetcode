class Solution {
public:
//ver 1
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


class Solution {
public:
// ver 2
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n - 1);
        string ans;
        int count = 1;
        for(int i = 1; i <= s.size(); ++i) {
            if(s[i] != s[i - 1] || i == s.size()) {
                ans.push_back(count + '0');
                ans.push_back(s[i - 1]);
                count = 1;
            }
            else {
                count++;
            }
        }
        return ans;
    }

};