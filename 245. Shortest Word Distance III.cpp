class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX, len = words.size();
        int index1 = -len, index2 = len;
        for(int i = 0; i < len; ++i) {
            if(word1 == word2 && words[i] == word1) {
                index2 = index1;
                index1 = i;
                ans = min(ans, abs(index1 - index2));
            }
            else if(words[i] == word1) {
                index1 = i;
                ans = min(ans, abs(index1 - index2));
            }
            else if(words[i] == word2) {
                index2 = i;
                ans = min(ans, abs(index1 - index2));
            }
        }
        return ans;
    }
};