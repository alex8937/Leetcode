class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // version 1: hashtable => Time: O(m + n) Space: O(m)
        unordered_map<int, int> dict1;
        for(auto num : nums1) {
            dict1[num]++;
        }
        vector<int> ans;
        for(auto num : nums2) {
            if(dict1.count(num) && dict1[num] > 0) {
                ans.emplace_back(num);
                dict1[num]--;
            }
        }
        return ans;
        //version 2: sorted => Time: O(m + n) for already sorted; Space: O(m)
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                ans.emplace_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
        //version 3: sort + binary search => Time: O(nlogm) for already sorted; Space: O(m)
        vector<int> ans;
        auto& n1 = (nums1.size() < nums2.size()) ? nums1 : nums2;
        auto& n2 = (nums1.size() >= nums2.size()) ? nums1 : nums2;
        sort(n2.begin(), n2.end());
        vector<bool> used(n2.size(), false);
        for(auto num : n1) {
            int index = find(n2, used, num);
            if(index >= 0) {
                used[index] = true;
                ans.emplace_back(num);
            }
        }
        return ans;

    }
    
    int find(const vector<int>& n2,const vector<bool>& used,const int& num) {
        int start = 0, end = n2.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(n2[mid] > num) {
                end = mid;
            }
            else if (n2[mid] < num) {
                start = mid;
            }
            else {
                if(used[mid]) start = mid;
                else end = mid;
            }
        }
        if(n2[start] == num && !used[start]) return start;
        if(n2[end] == num && !used[end]) return end;
        return -1;
    }
};