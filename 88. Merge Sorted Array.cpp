class Solution {
public:
//ver1
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

class Solution {
public:
//ver2
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};