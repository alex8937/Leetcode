class Solution {
public:
    //ver 1: two pointers O(n)
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, len = INT_MAX, sum = 0; 
        // start points to the first elment of the subarray
        // end points to the next to be the end of subarry;
        while(end < nums.size()) {
            while(end < nums.size() && sum < s) {
                sum += nums[end++];
            }
            while(start <= end && sum >= s) {
                len = min(len, end - start);
                sum -= nums[start++];
            }
        }
        return (len == INT_MAX)? 0 : len;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    // Binary search O(nlogn)
        auto sums = accumulate(nums);
        int len = INT_MAX;
        for(int start = 1; start < sums.size(); ++start) {
            int low = lowerbound(sums, start, sums[start - 1] + s);
            if(low != -1) len = min(len, low - start + 1);
        }
        return (len == INT_MAX)? 0 : len;
    }
    
    vector<int> accumulate(vector<int> nums) {
        vector<int> sums(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }
    
    int lowerbound(vector<int> sums, int start, int target) {
        int end = sums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(sums[mid] < target) start = mid + 1;
            else end = mid;
        }
        return (sums[start] >= target)? start : -1;
    }
};