class Solution {
public:
// iteration
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

class Solution {
public:
//recursion
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return vector<vector<int>>();
        auto all = generate(numRows - 1);
        vector<int> row = vector<int>(numRows, 1);
        for(int i = 1; i < int(row.size()) - 1; ++i) {
            row[i] = all.back()[i] + all.back()[i - 1];
        }
        all.push_back(row);
        return all;
    }
};