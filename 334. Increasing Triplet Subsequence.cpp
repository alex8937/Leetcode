class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_min = INT_MAX, second_min = INT_MAX;
        for(int num : nums) {
            if(num <= first_min) {
                first_min = num;
            }
            else if(num <= second_min) {
                second_min = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};