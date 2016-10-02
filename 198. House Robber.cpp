class Solution {
public:
    int rob(vector<int>& nums) {
/*
Include this house:
i = num[k] + e (money of this house + money robbed excluding the previous house)

Exclude this house:
e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
*/
        int include = 0, exclude = 0;
        for(auto n : nums) {
            int temp = include;
            include = exclude + n;
            exclude = max(temp, exclude);
        }
        return max(include, exclude);
    }
};
