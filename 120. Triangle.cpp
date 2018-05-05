class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> ans = triangle.back();
        for(int i = triangle.size() - 2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                ans[j] = triangle[i][j] + min(ans[j], ans[j + 1]);
            }
        }
        return ans[0];
    }
};