class Solution {
public:
//ver 1
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int record = nums[0], tail = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != record) {
                record = nums[tail++] = nums[i];
            }
        }
        return tail;
        
    }
};


class Solution {
public:
//ver 2
    int removeDuplicates(vector<int>& nums) {
        int last = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0 || nums[i] > nums[i - 1]) {
                nums[last++] = nums[i];
            }
        }
        return last;
    }
};

class Solution {
public:
//ver 3
    int removeDuplicates(vector<int>& nums) {
        int last = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            if(nums[i] != nums[i - 1] || i == nums.size()) {
                nums[last++] = nums[i - 1];
            }
        }
        return last;
    }
};