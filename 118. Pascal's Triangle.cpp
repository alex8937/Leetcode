class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; ++i) {
            vector<int> dummy(i, 1);
            for(int j = 1; j <= i - 2; ++j) {
                int temp = ans.back()[j] + ans.back()[j - 1];
                dummy[j] = temp;
            }
            ans.push_back(dummy);
        }
        return ans;
    }
};