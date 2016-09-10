class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ans = words.size();
        int index1 = -words.size(), index2 = words.size();
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                index1 = i;
                ans = min(ans, abs(index1 - index2));
            }
            if(words[i] == word2) {
                index2 = i; 
                ans = min(ans, abs(index1 - index2));
            }
        }
        return ans;
    }
};