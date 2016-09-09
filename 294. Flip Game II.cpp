class Solution {
public:
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