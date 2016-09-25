class Solution {
public:
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cand;
        vector<vector<bool>> valid(s.size(), vector<bool>(s.size(), false));
        initial(valid,s);
        int level = 0;
        help(ans, cand, s, level, valid);
        return ans;
    }
    void help(vector<vector<string>>& ans, vector<string>& cand, const string& s, int start,const vector<vector<bool>>& valid) {
        if(start == s.size()) {
            ans.push_back(cand);
            return;
        }
        for(int end = start; end < s.size(); ++end) {
            if(valid[start][end]) {
                cand.push_back(s.substr(start, end - start + 1));
                help(ans, cand, s, end + 1, valid);
                cand.pop_back();
            }
        }
    }
    
    void initial(vector<vector<bool>>& v, string s) {
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j <= i; ++j) {
                if(i == j) {
                    v[j][i] = true;
                }
                else {
                    v[j][i] = (s[i] == s[j]) && (i - j == 1 || v[j + 1][i - 1]);
                }
            }
        }
    }
};