class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> ans(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        long temp = 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            temp *= nums[i + 1];
            ans[i] *= temp;
        }
        return ans;
    }
};

//=====================================================


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = nums;
        for(int i = 1; i < nums.size(); ++i) {
           ans[i] = ans[i - 1] * nums[i];
        }
        int right = 1;
        for(int i = int(nums.size()) - 1; i >= 0; --i) {
            ans[i] = ((i == 0)? 1 : ans[i - 1]) * right;
            right *= nums[i];
        }
        return ans;
        
    }
};