class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        return (findKSortedArrays(nums1, 0, nums2, 0, (len + 1) / 2) + findKSortedArrays(nums1, 0, nums2, 0, (len + 2) / 2)) / 2.0;
    }
    
    double findKSortedArrays(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        if(s1 >= nums1.size()) return nums2[s2 + k - 1];
        if(s2 >= nums2.size()) return nums1[s1 + k - 1];
        if(k == 1) return min(nums1[s1], nums2[s2]);
        int val1 = (s1 + k / 2 - 1 < nums1.size())? nums1[s1 + k / 2 - 1] : INT_MAX;
        int val2 = (s2 + k / 2 - 1 < nums2.size())? nums2[s2 + k / 2 - 1] : INT_MAX;
        return (val1 < val2)? findKSortedArrays(nums1, s1 + k / 2, nums2, s2, k - k / 2) : findKSortedArrays(nums1, s1, nums2, s2 + k / 2, k - k / 2);
    }
};