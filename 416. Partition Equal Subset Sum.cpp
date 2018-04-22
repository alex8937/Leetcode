class Solution {
public:
// Using bitset and left shift
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return 0;
        sum >>= 1;
        bitset<10001> dict(1);
        for(int n : nums) {
            dict |= (dict << n);
            if(dict[sum]) return true;
        }
        return false;
    }
};

class Solution {
public:
// dynamic programming
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        sum >>= 1;
        vector<bool> dict(sum + 1, false);
        dict[0] = true;
        for(int n : nums) {
            for(int i = sum; i >= n; --i) {
                if(dict[i - n]) dict[i] = true;
                if(dict[sum]) return true;
            }
        }
        return false;
    }
};