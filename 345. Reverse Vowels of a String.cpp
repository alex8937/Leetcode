class Solution {
public:
    inline bool isvowel(char c) {
        c = tolower(c);
        return (c == 'a') || (c == 'i') || (c == 'e') || (c == 'o') || (c == 'u');
    }
    string reverseVowels(string s) {
        int start = 0, end = s.size() - 1;
        while(start < end) {
            while(start < end && !isvowel(s[start])) {
                start++;
            }
            while(start < end && !isvowel(s[end])) {
                end--;
            }
            swap(s[start++], s[end--]);
        }
        return s;
    }
};