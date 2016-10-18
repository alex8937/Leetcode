class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> dict;	// key: sum, value: index
        dict[0] = -1;
        int len = 0, sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(dict.count(sum - k)) len = max(len, i - dict[sum - k]);
            if(!dict.count(sum)) dict[sum] = i;
        }
        return len;
    }
};