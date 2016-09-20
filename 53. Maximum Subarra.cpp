class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    // version 1: dp
        if(nums.empty()) return 0;
        int cur = nums[0];
        int ans = cur;
        for(int i = 1; i < nums.size(); ++i) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(cur, ans);
        }
        return ans;
        
    // version2: Divide & Conquer
        return maxSub(0, nums.size() - 1, nums);
    }
    
    int maxSub(int start, int end, const vector<int>& nums) {
        if(start == end) return nums[start];
        int mid = start + (end - start) / 2;
        int leftmax = maxSub(start, mid, nums);
        int rightmax = maxSub(mid + 1, end, nums);
        int midleft = nums[mid], midright = nums[mid + 1]; 
        int curleft = midleft, curright = midright;
        for(int i = mid - 1; i >= start; --i) {
            curleft = curleft + nums[i];
            midleft = max(midleft, curleft);
        }
        for(int i = mid + 2; i <= end; ++i) {
            curright = curright + nums[i];
            midright = max(midright, curright);
        }
        return max(midleft + midright, max(leftmax, rightmax));
        
    }
};