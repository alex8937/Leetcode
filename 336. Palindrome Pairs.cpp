class Solution {
public:
	//Complexity: O(nk^2)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); ++i) {
            dict[words[i]] = i;
        }
        set<vector<int>> ans;
        for(int i = 0; i < words.size(); ++i) {
            string w = words[i];
            vector<string> left = patch(w, true);
            for(auto str : left) {
                if(dict.count(str) && dict[str] != dict[words[i]]) {
                    ans.insert(vector<int>{dict[str], i});
                }
            }
            reverse(w.begin(), w.end());
            vector<string> right = patch(w, false);
            for(auto str : right) {
                if(dict.count(str) && dict[str] != dict[words[i]]) {
                    ans.insert(vector<int>{i, dict[str]});
                }
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
    
    vector<string> patch(string s, bool left) {
        vector<string> ans;
        for(int i = 0; i <= s.size(); ++i) {
            bool valid = true;
            for(int j = 1; j <= i / 2; ++j) {
                valid &= (s[i / 2 - j] == s[i / 2 + j - (1 - i % 2)]);
                if(!valid) break;
            }
            if(valid) {
                string cand = s.substr(i);
                if(left) reverse(cand.begin(), cand.end());
                ans.push_back(cand);
            }
        }
        return ans;
    }
};