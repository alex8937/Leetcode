class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		// backtracking
        vector<string> ans;
        help(ans, "", s, 0, 0);
        return ans;
    }
    void help(vector<string>& ans, string cand, const string& s, int start, int cnt) {
        if(cnt > 4) return;
        if(start == s.size() && cnt == 4) {
            ans.push_back(cand);
        }
        for(int len = 1; len <= 3 && start + len <= s.size(); ++len) {
            string sub = s.substr(start, len);
            if(sub[0] == '0' && len > 1 || stoi(sub) > 255) continue;
            auto patch = (cnt < 3)? "." : "";
            help(ans, cand + sub + patch, s, start + len, cnt + 1);
        } 
    }

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		// iteration
        vector<string> ans;
        for(int len1 = 1; len1 <= 3; ++len1) {
            for(int len2 = 1; len2 <= 3; ++len2) {
                for(int len3 = 1; len3 <= 3; ++len3) {
                    for(int len4 = 1; len4 <= 3; ++len4) {
                        if(len1 + len2 + len3 + len4 != s.size()) continue;
                        int val1 = stoi(s.substr(0, len1));
                        int val2 = stoi(s.substr(len1, len2));
                        int val3 = stoi(s.substr(len1 + len2, len3));
                        int val4 = stoi(s.substr(len1 + len2 + len3, len4));
                        if(val1 > 255 || val2 > 255 || val3 > 255 || val4 > 255) continue;
                        string cand = to_string(val1) + '.' +  to_string(val2) + '.' + to_string(val3) + '.' + to_string(val4);
                        if(cand.size() == s.size() + 3) ans.push_back(cand);
                    }            
                }            
            }            
        }
        return ans;
    }
    
};    