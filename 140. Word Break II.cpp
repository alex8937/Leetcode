class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return helper(s, memo, dict);
    }
    vector<string> helper(string s, unordered_map<string, vector<string>>& memo, unordered_set<string>& dict) {
        if(memo.count(s)) return memo[s];
        vector<string> ans;
        if(dict.count(s)) ans.push_back(s);
        for(int i = 1; i < s.size(); ++i) {
            string head = s.substr(0, i);
            if(!dict.count(head)) continue;
            string tail = s.substr(i);
            auto tail_list = helper(tail, memo, dict);
            combine(head, tail_list);
            ans.insert(ans.end(), tail_list.begin(), tail_list.end());
        }
        memo[s] = ans;
        return ans;
    }
    
    void combine(string& head, vector<string>& strs) {
        for(int i = 0; i < strs.size(); ++i) {
            strs[i] = head + " " + strs[i];
        }
    }
};