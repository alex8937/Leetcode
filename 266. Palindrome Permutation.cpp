class Solution {
public:
    bool canPermutePalindrome(string s) {
      //version 1:  bitset
        bitset<128> dict;
        for (auto ch : s) {
            dict[ch].flip();
        }
        return (dict.count() <= 1);
      //version 2: unordered_set
        unordered_set<char> dict;
        for (auto ch : s) {
            if(dict.count(ch)) {
                dict.erase(ch);
            }
            else {
                dict.insert(ch);
            }
        }
        return dict.size() <= 1;
    }
};