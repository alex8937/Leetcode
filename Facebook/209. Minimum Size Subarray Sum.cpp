class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, len = INT_MAX, sum = 0;
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