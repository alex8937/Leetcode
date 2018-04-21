class Solution {
private:
    unordered_map<char, string> dict = {{'2' , "abc"}, {'3' , "def"}, {'4' , "ghi"}, {'5' , "jkl"}, {'6' , "mno"}, {'7' , "pqrs"}, {'8' , "tuv"}, {'9' , "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
	// Recursion
	vector<string> ans;
        if(digits.size() == 0) return ans;
        helper(ans, "", 0, digits);
        return ans;
    }
    void helper(vector<string>& ans, string cand, int index, const string& digits) {
        if(index == digits.size()) {
            ans.push_back(cand);
            return;
        }
        for(char c : dict[digits[index]]) {
            cand.push_back(c);
            helper(ans, cand, index + 1, digits);
            cand.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
	// Iteration    
        vector<string> ans;
        if(digits.size() == 0) return ans;
        vector<string> last = {""};
        for(int index = 0; index < digits.size(); ++index) {
            ans.clear();
            for(char c : dict[digits[index]]) {
                for(int i = 0; i < last.size(); ++i) {
                    ans.push_back(last[i] + c);
                }
            }
            last = ans;
        }
        return ans;
    }
};