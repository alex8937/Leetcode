class Solution {
public
    vectorint twoSum(vectorint& nums, int target) {
        unordered_mapint ,int dict;
        vectorint ans;
        for(int i = 0; i  nums.size(); ++i) {
            if(dict.count(target - nums[i])) {
                ans.push_back(dict[target - nums[i]]);
                ans.push_back(i);
                break;
            } 
            dict[nums[i]] = i;
        }
        return ans;
    }
};