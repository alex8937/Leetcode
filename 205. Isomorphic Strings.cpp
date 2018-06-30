class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int dict1[256] = {0}, dict2[256] = {0};
        for(int i = 0; i < s.size(); ++i) {
            if(dict1[s[i]] != dict2[t[i]]) return false;
            dict1[s[i]] = dict2[t[i]] = i + 1;
        }
        return true;
    }
};