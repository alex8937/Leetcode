class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int start = 0, end = height.size() - 1;
        while(start < end) {
            int h = min(height[start], height[end]);
            ans = max(ans, h * (end - start));
            while(start < end && height[start] <= h) start++;
            while(start < end && height[end] <= h) end--;
        }
        return ans;
    }
};