class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        if(s.size() < 2) return ans;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == '+' && s[i + 1] == '+') {
                string temp = s.substr(0, i) + "--" + s.substr(i + 2);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};