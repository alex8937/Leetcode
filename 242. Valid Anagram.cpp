class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dict(26, 0);
        for(char c : s) {
            dict[c - 'a']++;
        }
        for(char c : t) {
            dict[c - 'a']--;
        }   
        for(auto i : dict) {
            if(i) return false;
        }
        return true;
        
    }
};