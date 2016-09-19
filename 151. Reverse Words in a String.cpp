class Solution {
public:
    void reverseWords(string &s) {
        string ans;
        int end = s.size(); // end is the first space after a word
        for(int start = s.size() - 1; start >= 0; --start) {
            if(s[start] == ' ') {
                end = start;
            }
            else if(start == 0 || s[start - 1] == ' ') {
                if(!ans.empty()) ans.push_back(' ');
                ans.append(s.substr(start, end - start));
            }
        }
        s = ans;
    }
};