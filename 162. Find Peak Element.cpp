class Solution {
// Divide and Conquer
public:
    int findPeakElement(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }
    int help(const vector<int>& nums, int start, int end) {
        if(start == end) return start;
        int mid = start + (end - start) / 2;
        if(nums[mid] < nums[mid + 1]) return help(nums, mid + 1, end);
        else return help(nums, start, mid);
    }
};

class Solution {
public:
// Binary search
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid + 1] > nums[mid]) start = mid + 1;
            else end = mid;
        }
        return end;
    }
};