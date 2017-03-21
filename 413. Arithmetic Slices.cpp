class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        vector<int> dp(A.size(), 0); //dp[i] is the number of arithmic sequence ending with A[i]
        int sum = 0, del = A[1] - A[0];
        for(int i = 2; i < A.size(); ++i) {
            if(del == A[i] - A[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                del = A[i] - A[i - 1];
            }
            sum += dp[i];
        }
        return sum;
    }
};