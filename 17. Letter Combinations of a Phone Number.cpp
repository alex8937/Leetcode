class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      if(digits.size() == 0) return ans;
      string cand;
      dfs(ans, cand, 0, digits);
      return ans;
    }
    
    void dfs(vector<string>& ans, string& cand, int start, const string& digits) {
      if(start == digits.size()) {
        ans.push_back(cand);
        return;
      }
      string pool = getstr(digits[start] - '0');
      for(auto c : pool) {
        cand.push_back(c);
        dfs(ans, cand, start + 1, digits);
        cand.pop_back();
      }
    }
    
    string getstr(int n) {
        switch (n) {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
            default: return "";
        }
    }
};