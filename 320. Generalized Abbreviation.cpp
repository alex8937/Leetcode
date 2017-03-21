class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        help(ans, "", word, 0, 0);
        return ans;
    }
    void help(vector<string>& ans, string cand, const string& word, int start, int count) {
        if(start == word.size()) {
            if(count > 0) {
                cand += to_string(count);
            }
            ans.push_back(cand);
            return;
        }
        help(ans, cand, word, start + 1, count + 1);
        help(ans, cand + ((count == 0)? "" : to_string(count)) + word[start], word, start + 1, 0);
    }
};