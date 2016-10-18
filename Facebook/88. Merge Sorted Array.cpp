class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0) {
            if(A[i] >= B[j]) A[i + j + 1] = A[i--];
            else A[i + j + 1] = B[j--];
        }
        while(j >= 0) {
            A[j] = B[j--];
        }        
    }
};