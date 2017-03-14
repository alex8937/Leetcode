class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        int pool = (1 << maxChoosableInteger) - 1;
        unordered_map<int, bool> dict;
        return helper(pool, desiredTotal, dict);
    }
    
    bool helper(int pool, int desiredTotal, unordered_map<int, bool>& dict) {
        if(get_max(pool) >= desiredTotal) return true;
        int key = pool | (desiredTotal << 20);
        if(dict.count(key)) return dict[key];
        for(int mask = (1<<19); mask != 0; mask = mask >> 1) {
            if(pool & mask) {
                int choose = get_max(pool & mask);
                if(!helper(pool - mask, desiredTotal - choose, dict)) {
                    dict[key] = true;
                    return true;                    
                }
            }
        }
        dict[key] = false;
        return false;
    }
    
    int get_max(int pool) {
        if(pool <= 0) return 0;
        return int(log2(pool)) + 1;
    }
};