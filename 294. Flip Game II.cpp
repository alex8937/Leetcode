class Solution {
public:
// version 1: backtracking
    bool canWin(string s) {
        unordered_map<string, bool> dict;
        return canWin_helper(dict, s);
    }
    bool canWin_helper(unordered_map<string, bool>& dict, string s) {
        if(dict.count(s)) return dict[s];
        for(int i = 0; i < int(s.size()) - 1; ++i) {
            if(s.substr(i, 2) == "++") {
                string copy = s.substr(0, i) + "--" + s.substr(i + 2);
                if(!canWin_helper(dict, copy)) {
                    dict[s] = true;
                    return true;
					//If rival cannot win, then player can win
                }
            }
        }
		//Player cannot win
        dict[s] = false;
        return false;
    }
};

public:
	// nim game
    int findfirstmissing(const unordered_set<int>& dict) {
        int ans = dict.size();
        for(int i = 0; i < dict.size(); ++i) {
            if(!dict.count(i)) return i;
        }
        return ans;
    }
    bool canWin(string s) {
        int maxplus = 0;
        int plus = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '+') {
                plus++;
            }
            if(s[i] == '-' || i == s.size() - 1) {
                maxplus = max(plus, maxplus);
                plus = 0;
            }
        }
        vector<int> nims(maxplus + 1, 0);
        for(int len = 2; len <= max_plus; ++len) {
            unordered_set<int> dict;
            for(int first = 0; first <= len - first - 2; ++first) {
                int second = len - first - 2;
                dict.insert(nims[first]^nims[second]);
            }
            nims[len] = firstmissing(dict);
        }
        plus = 0;
        int ans = nims[0];
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '+') {
                plus++;
            }
            if(s[i] == '-' || i == s.size() - 1) {
                ans ^= nims[plus];
                plus = 0;
            }
        }
        return ans != 0;
    }
};

//dfs + hash_table memoization
//Demo for "++++++"
/*
++++++
*--++++
**----++
***------
***------ False
**----++ True
**--+--+
**--+--+ False
*--++++ True
*+--+++
**+----+
**+----+ False
*+--+++ True
*++--++
**----++
**----++ True
**++----
***------
***------ False
**++---- True
*++--++ False
*/