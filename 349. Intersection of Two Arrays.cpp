class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			//version 1: use Set
        auto& long_nums = (nums1.size() > nums2.size())? nums1 : nums2;
        auto& short_nums = (nums1.size() > nums2.size())? nums2 : nums1;
        unordered_set<int> dict(short_nums.begin(), short_nums.end()), ans;
        for(auto n : long_nums) {
            if(dict.count(n)) {
                ans.insert(n);
            }
        }
        return vector<int>(ans.begin(), ans.end());
			//version 2: binary search
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end()); 
        vector<int> sol;
        if(nums1.empty() || nums2.empty()) return sol;  // edge case
        int last = nums1[0];
        for(int i = 0; i < nums1.size(); ++i) {
            if(i != 0 && nums1[i] == last) continue;
            if(exist(nums2, nums1[i])) {
                sol.emplace_back(nums1[i]);
                last = nums1[i];
            }
        }
        return sol;
        
    }
		//version 2: binary search cont.
    bool exist(const vector<int>& nums, const int& n) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(n > nums[mid]) {
                start = mid + 1;
            }
            else if(n < nums[mid]) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};