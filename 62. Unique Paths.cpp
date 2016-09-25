class Solution {
public:
    int uniquePaths(int m, int n) {
        int small = min(m, n);
        int big = max(m, n);
        vector<int> dict(small, 1);
        for(int i = 1; i < big; ++i) {
           for(int j = 1; j < small; ++j) {
               dict[j] = dict[j] + dict[j - 1];
           }
        }
        return dict.back();
        
    }
};