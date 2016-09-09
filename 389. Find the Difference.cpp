class Solution {
public:
    char findTheDifference(string s, string t) {
			//version 1: 
        int num = 0;
        for (char c : s) {
            num ^= 1 << (c- 'a');
        }
        for (char c : t) {
            num ^= 1 << (c- 'a');
        }
        return int(log2(num)) + 'a';
		  //version 2:
        int num = 0;
        for (char c : s) {
            num ^= c;
        }
        for (char c : t) {
            num ^= c;
        }
        return char(num);			
    }
};