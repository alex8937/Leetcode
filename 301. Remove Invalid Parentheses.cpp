class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int left = 0;
        int right = 0;
        for(auto c : s) {
            if(c == '(') left++;
            if(c == ')') {
                if(left != 0) left--;
                else right++;
            }
        }
        helper(s, 0, left, right, 0, "", ans);
        return vector<string>(ans.begin(), ans.end());
    }
private:
    void helper(string s, int index, int left, int right, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()) {
            if(left == 0 && right == 0 && pair == 0) result.insert(path);
            return;
        }
        if(s[index] != '(' && s[index] != ')') helper(s, index + 1, left, right, pair, path + s[index], result);
        else {
            if(s[index] == '(') {
                if(left > 0) helper(s, index + 1, left - 1, right, pair, path, result);
                helper(s, index + 1, left, right, pair + 1, path + s[index], result);
            }
            else {
                if(right > 0) helper(s, index + 1, left, right - 1, pair, path, result);
                if(pair > 0) helper(s, index + 1, left, right, pair - 1, path + s[index], result);
            }
        }
    }
};