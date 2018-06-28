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



class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_set<string> pool;
        unordered_map<char, string> dict;
        int index = 0;
        stringstream ss(str);
        string word;
        while(ss >> word) {
            if(index == pattern.size()) return false;
            if(dict.count(pattern[index])) {
                if(dict[pattern[index]] != word) return false;
            }
            else {
                if(pool.count(word)) return false;
                pool.insert(word);
                dict[pattern[index]] = word;
            }
            index++;
        }
        return index == pattern.size();
    }
};


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_set<string> pool;
        unordered_map<char, string> dict;
        auto str_list = split(str);
        return helper(str_list, pattern, 0 ,0, pool, dict);   
    }
    
    bool helper(vector<string>& str_list, string& pattern, int i, int j, unordered_set<string>& pool, unordered_map<char, string>& dict) {
        if(i == str_list.size() && j == pattern.size()) return true;
        if(i == str_list.size() || j == pattern.size()) return false;
        auto c = pattern[j];
        auto word = str_list[i];
        if(dict.count(c)) {
            if(word != dict[c]) return false;
        }
        else {
            if(pool.count(word)) return false;
            pool.insert(word);
            dict[c] = word;                   
        }
        return helper(str_list, pattern, i + 1, j + 1, pool, dict);
    }
    
    vector<string> split(string str) {
        vector<string> ans;
        stringstream ss(str);
        string word;
        while(ss >> word) {
            ans.push_back(word);
        }
        return ans;
    }  
};