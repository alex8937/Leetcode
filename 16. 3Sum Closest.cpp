class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int diff = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(abs(target - sum) < diff) {
                    diff = abs(target - sum);
                    ans = sum;
                }
                if(sum > target) {
                    end--;
                }
                else if(sum < target) {
                    start++;
                }
                else {
                    return target;
                }
            }
        }
        return ans;
    }
};