class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int last = 0;
		int count = 1;
		for (int i = 1; i <= nums.size(); ++i) {
			if (i == nums.size() || nums[i] != nums[i - 1]) {
				nums[last++] = nums[i - 1];
				count = 1;
			}
			else if (nums[i] == nums[i - 1] && count == 1) {
				nums[last++] = nums[i - 1];
				count++;
			}
		}
		return last;
	}
};