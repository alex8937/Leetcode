class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dict(26, 0);
        for(char c : magazine) {
            dict[c - 'a']++;
        }
        for(char c : ransomNote) {
            dict[c - 'a']--;
            if(dict[c - 'a'] < 0) return false;
        }
        return true;
    }
};