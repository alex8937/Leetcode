class Solution {
public:
    string minWindow(string S, string T) {
        int n = T.size(), m = S.size();
        vector<int> ans(m, 0);
        for(int i = 0; i < n; ++i) {
            vector<int> temp(m, 0);
            for(int j = 0; j < m; ++j) {
                if(S[j] == T[i] && ans[j - 1] >= i) temp[j] = ans[j - 1] + 1;
                else if(j > 0 && temp[j - 1] > 0) temp[j] = temp[j - 1] + 1;
            }
            ans.swap(temp);
        }
        int minlen = INT_MAX, start = -1;
        for(int j = 0; j < m; ++j) {
            if(ans[j] > 0 && ans[j] < minlen) {
                minlen = ans[j];
                start = j;
            }
        }
        return start == -1? "" : S.substr(start - minlen + 1, minlen);
    }
};