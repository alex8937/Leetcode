class Solution {
public:
//DFS
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
        // left, right being the number of left right parentheses to be deleted
        helper(s, 0, left, right, 0, "", ans);
        return vector<string>(ans.begin(), ans.end());
    }
private:
    void helper(string s, int index, int left, int right, int pair, string path, unordered_set<string>& result) {
        if(left < 0 || right < 0 || pair < 0) return; // if the deletion budget is not enough, this branch fails
        if(index == s.size()) {
            if(left == 0 && right == 0 && pair == 0) result.insert(path);
            return;
        }
        if(s[index] != '(' && s[index] != ')') helper(s, index + 1, left, right, pair, path + s[index], result);
        else {
            if(s[index] == '(') {
                helper(s, index + 1, left - 1, right, pair, path, result);
                helper(s, index + 1, left, right, pair + 1, path + s[index], result);
            }
            else {
                helper(s, index + 1, left, right - 1, pair, path, result);
                helper(s, index + 1, left, right, pair - 1, path + s[index], result);
            }
        }
    }
};


class Solution {
public:
//BFS
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> qu;
        unordered_set<string> visit;
        qu.push(s);
        visit.insert(s);
        bool found = false;
        while(!qu.empty()) {
            int len = qu.size();
            for(int i = 0; i < len; ++i) {
                auto head = qu.front();
                qu.pop();
                if(valid(head)) {
                    found = true;
                    ans.push_back(head);
                }
                else {
                    for(int j = 0; j < head.size(); ++j) {
                        if(head[j] != '(' && head[j] != ')') continue;
                        auto str = head.substr(0, j) + head.substr(j + 1);
                        if(!visit.count(str)) {
                            qu.push(str);
                            visit.insert(str);
                        }
                    }
                }
            }
            if(found) break;
        }
        
        return ans;
    }
    bool valid(string s) {
        int cnt = 0;
        for(auto c : s) {
            if(c == '(') cnt++;
            if(c == ')') {
                if(cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
};