class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        string word;
        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;
        int i = 0;
        while(ss >> word) {
            if(i == pattern.size()) return false;
            if(dict1[pattern[i]] != word) return false;
            if(dict2[word] != pattern[i]) return false;
            dict1[pattern[i]] = word;
            dict2[word] = pattern[i++];
        }
        return i == pattern.size();
    }
};