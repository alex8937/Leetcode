class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, f = 0;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            sum += A[i];
            f += i * A[i];
        }
        int ans = f;
        for(int i = n - 1; i >= 1; --i) {
            f += sum - n * A[i];
            ans = max(ans, f);
        } 
        return ans;
    }
};