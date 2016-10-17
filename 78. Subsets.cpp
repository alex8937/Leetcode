class Solution {
public:
// Recursion
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cand;
        help(ans, cand, 0, nums);
        return ans;
    }
    void help(vector<vector<int>>& ans, vector<int>& cand, int index, const vector<int>& nums) {
        ans.push_back(cand);
        for(int i = index; i < nums.size(); ++i) {
            cand.push_back(nums[i]);
            help(ans, cand, i + 1, nums);
            cand.pop_back();
        }
        
    }
};

class Solution {
public:
// Iteration
/*
Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        for(int i = 0; i < nums.size(); ++i) {
            int len = ans.size();
            for(int j = 0; j < len; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
// Bit Manipulation
/*
[], [], [], [], [], [], [], []
[], [1], [], [1], [], [1], [], [1]
[], [1], [2], [1, 2], [], [1], [2], [1, 2]
[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(pow(2, int(nums.size())), vector<int>());
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < ans.size(); ++j) {
                if((j >> i) & 1) ans[j].push_back(nums[i]);
            }
        }
        return ans;
    }
};