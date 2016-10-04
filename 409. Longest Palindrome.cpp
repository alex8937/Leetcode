class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> dict;
        int ans = 0;
        for(char c : s) {
            if(dict.count(c)) {
                ans += 2;
                dict.erase(c);
            }
            else {
                dict.insert(c);
            }
        }
        int single = (dict.empty())? 0 : 1;
        return ans + single;
    }
};