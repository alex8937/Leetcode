class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2, cnt1 = 0, cnt2 = 0;
        for(int n : nums) {
            if(n == num1) {
                cnt1++;
            }
            else if(n == num2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                num1 = n;
                cnt1++;
            }
            else if(cnt2 == 0) {
                num2 = n;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(int n : nums) {
            if(n == num1) cnt1++;
            if(n == num2) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > nums.size() / 3) ans.push_back(num1);
        if(cnt2 > nums.size() / 3) ans.push_back(num2);
        return ans;
    }
};