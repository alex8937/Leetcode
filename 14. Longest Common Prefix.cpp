class Solution {
public:
    string common(const string& p, const string& q) {
        string pre;
        int i = 0, j = 0;
        while(i < p.size() && j < q.size()) {
            if(p[i++] == q[j++]) pre.push_back(p[i - 1]);
            else break;
        }
        return pre;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string pre = (strs.empty())? "" : strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            pre = common(pre, strs[i]);
        }
        return pre;
    }

};