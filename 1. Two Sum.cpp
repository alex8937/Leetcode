class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); ++i) {
            if(dict.count(target - nums[i])) {
                return vector<int>{dict[target - nums[i]], i};
            }
            dict[nums[i]] = i;
        }
        return vector<int>{};
    }
};