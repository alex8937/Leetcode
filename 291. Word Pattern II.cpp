class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> dict;
        unordered_set<string> pool;
        return helper(str, pattern, 0, 0, dict, pool);
    }
    bool helper(string& str, string& pattern, int i, int j, unordered_map<char, string>& dict, unordered_set<string>& pool) {
        if(i == str.size() && j == pattern.size()) return true;
        if(i == str.size() || j == pattern.size()) return false;
        auto c = pattern[j];
        if(dict.count(c)) {
            string match_str = dict[c];
            for(int k = 0; k < match_str.size(); ++k) {
                if(i == str.size() || match_str[k] != str[i]) return false;
                i++;
            }
            return helper(str, pattern, i, j + 1, dict, pool);
        }
        
        for(int k = i; k < str.size(); ++k) {
            string match_str = str.substr(i, k - i + 1);
            if(pool.count(match_str)) continue;
            dict[c] = match_str;
            pool.insert(match_str);
            if(helper(str, pattern, k + 1, j + 1, dict, pool)) return true;
            dict.erase(c);
            pool.erase(match_str);
        }
        return false;
    }
};