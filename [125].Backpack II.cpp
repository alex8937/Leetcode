class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<int> dp(m + 1, 0);
        int ans = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = m; j >= 1; --j) {
                if(i == 0) dp[A[i]] = V[i];
                else if(j >= A[i]) dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};