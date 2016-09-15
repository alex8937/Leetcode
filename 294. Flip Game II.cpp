class Solution {

public:
	// version 1: backtracking
    bool canWin(string s) {
        unordered_map<string, bool> dict;
        return canWin_helper(s, dict);
    }
    
    bool canWin_helper(string s, unordered_map<string, bool>& dict) {
        if(dict.count(s)) return dict[s];
        for(int i = 0; i < int(s.size()) - 1; ++i) {
            if(s.substr(i,2) == "++") {
                string temp = s.substr(0,i) + "--" + s.substr(i + 2);
                if(!canWin_helper(temp,dict)) {
                    dict[temp] = false;
                    return true;		//Once find cannotwin in this level,
																		//it means canwin for rival in parent level
                }
                else {
                    dict[temp] = true;                    
                }

            }

        }
        return false;        
    }
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
        vector<int> nim(maxplus + 1, 0);
        for(int i = 2; i < nim.size(); ++i) {
            unordered_set<int> dict;
            for(int j = 0; j <= i - j - 2; ++j) {
                dict.insert(nim[j] ^ nim[i - j - 2]);
            }
            nim[i] = findfirstmissing(dict);
        }
        plus = 0;
        int ans = nim[0];
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '+') {
                plus++;
            }
            if(s[i] == '-' || i == s.size() - 1) {
                ans ^= nim[plus];
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