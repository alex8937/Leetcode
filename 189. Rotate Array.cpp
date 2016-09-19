class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = k % nums.size();
        reverse(nums.begin(), nums.end() - n);
        reverse(nums.end() - n, nums.end());
        reverse(nums.begin(), nums.end());
    }
};