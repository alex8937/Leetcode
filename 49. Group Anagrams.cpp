class Solution {
public:
    string pattern(string str) {
        string ans(26, '0');
        for(auto c : str) {
            ans[c - 'a']++;
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for(auto s : strs) {
            dict[pattern(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : dict) {
            ans.push_back(it.second);
        }
        return ans;
    }
};