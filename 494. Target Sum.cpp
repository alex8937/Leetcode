class Solution {
public:
// Alternative iteration
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(S > sum || S < -sum || (S + sum) % 2 == 1) return 0;
        vector<int> count(2 * sum + 1, 0);
        count[sum] = 1;
        for(int n : nums) {
            vector<int> temp(2 * sum + 1, 0);
            for(int i = 0; i < count.size(); ++i) {
                if(count[i] == 0) continue;
                temp[i + n] += count[i];
                temp[i - n] += count[i];
            }
            count = temp;
        }
        return count[S + sum];
    }
};

class Solution {
public:
// S = P (positive subset) - N (negative subset)
// 2P = S + (P + N) = S + sum
// P = (S + sum) / 2
// Find ways to create subsum P using nums (dynamic programming)
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(S > sum || S < -sum || (S + sum) % 2 == 1) return 0;
        return findSubsumWays(nums, (S + sum) >> 1);
    }
    
    int findSubsumWays(vector<int>& nums, int k) {
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for(int n : nums) {
            for(int i = k; i >= n; --i) {
                dp[i] += dp[i - n]; 
            }
        }
        return dp[k];
    }
};