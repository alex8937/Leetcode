class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() == t.size()) return onechange(s, t);
        if(s.size() == t.size() - 1) return onedelete(s, t);
        if(t.size() == s.size() - 1) return onedelete(t, s);
        return false;
    }
    bool onechange(string s, string t) {
        int diff = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != t[i]) diff++;
        }
        return diff == 1;
    }
    
    bool onedelete(string s, string l) {
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != l[i]) return s.substr(i) == l.substr(i + 1);
        }
        return true;
    }
};