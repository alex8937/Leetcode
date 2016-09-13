class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int occur = 0;
        for(int num : nums) {
            if(occur == 0) {
                occur++;
                ans = num;
            }
            else if(occur > 0) {
                if(num == ans) occur++;
                else occur--;
            }
        }
        return ans;
    }
};