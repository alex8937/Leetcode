class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindromeHelper(true, s) || validPalindromeHelper(false, s);
    }
    
    bool validPalindromeHelper(bool left, string s) {
        int count = 0;
        for(int start = 0, end = s.size() - 1; start < end; ++start, --end) {
            if(s[start] != s[end]) {
                if(count > 0) return false;
                else {
                    count++;
                    if(left) start--;
                    else end++;
                }
            }
        } 
        return true;
    }
};