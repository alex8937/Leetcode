class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i < word.size()  && j < abbr.size()) {
            if(isdigit(abbr[j]) && abbr[j] != '0'){
                int num = 0;
                while(j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + abbr[j++] - '0';
                }
                i += num;
            }
            else if(word[i++] != abbr[j++]) return false;
        }
        return (i == word.size()) && (j == abbr.size());
        
    }
};