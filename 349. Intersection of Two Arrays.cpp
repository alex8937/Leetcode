class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			//version 1: use Set
        unordered_set<int> dict1(nums1.begin(), nums1.end()); 
        unordered_set<int> sol;
        for(int i = 0; i < nums2.size(); ++i) {
            if(dict1.count(nums2[i])) sol.insert(nums2[i]);
        }
        return vector<int>(sol.begin(), sol.end());
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