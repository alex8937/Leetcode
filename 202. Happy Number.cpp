class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> dict;
        while(!dict.count(n)) {
            dict.insert(n);
            n = getnext(n);
        }
        return n == 1;
    }
    int getnext(int n) {
        int ans = 0;
        while(n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};