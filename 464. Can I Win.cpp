class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if(maxChoosableInteger >= desiredTotal) return true;
        unordered_map<int, bool> dict;
        return helper((1 << maxChoosableInteger) - 1, desiredTotal, dict);
    }
    
    bool helper(int remain, int desiredTotal, unordered_map<int, bool>& dict) {
        int cur_max = get_max(remain);
        if(cur_max >= desiredTotal) return true;
        int key = remain | (desiredTotal << 20);
        if(dict.count(key)) return dict[key];
        for(int i = cur_max; i >= 1; --i) {
            int mask = 1 << (i - 1);
            if(remain & mask) {
                if(!helper(remain & (~mask), desiredTotal - i, dict)) {
                    dict[key] = true;
                    return dict[key];
                }
            }
        }
        dict[key] = false;
        return  dict[key];
    }
    
    int get_max(int n) {
        return 32 - __builtin_clz(n);
    }
};