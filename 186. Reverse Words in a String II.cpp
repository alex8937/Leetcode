class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int start = 0;
        for(int end = 0; end < str.size(); ++end) {
            if(str[end + 1] == ' ' || end == int(str.size()) - 1) {
                int left = start, right = end;
                reverse(str.begin() + start, str.begin() + end + 1);
                start = end + 2;
            }
        }
        
    }
};