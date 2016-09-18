class Solution {
public:
    string pattern(string s) {
        string ans;
        if(s.size() == 1) {
            ans.push_back('a');
        }
        for(int i = 1; i < s.size(); ++i) {
            int diff = s[i] - s[i - 1];
            if(diff < 0) diff += 26;
            ans.push_back('0' + diff);
        }
        return ans;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> dict;
        for(auto str : strings) {
            dict[pattern(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            ans.push_back((*it).second);
        }
        return ans;
        
    }
};