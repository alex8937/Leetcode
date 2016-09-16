class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans = {1};
        int it2 = 0, it3 = 0, it5 = 0;
        for(int i = 2; i <= n; ++i) {
            int temp = min(ans[it2] * 2, min(ans[it3] * 3, ans[it5] * 5));
            ans.emplace_back(temp);
            if(temp == ans[it2] * 2) it2++;
            if(temp == ans[it3] * 3) it3++;
            if(temp == ans[it5] * 5) it5++;            
        }
        return ans.back();
    }
};