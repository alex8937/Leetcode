class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0 || nums1.empty() || nums2.empty()) return {};
        auto cmp = [&](pair<int, int>& p, pair<int, int>& q) {return nums1[p.first] + nums2[p.second] > nums1[q.first] + nums2[q.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<pair<int, int>> ans;
        pq.emplace(0, 0);
        while(!pq.empty() && ans.size() < k) {
            auto temp = pq.top();
            pq.pop();
            ans.emplace_back(nums1[temp.first], nums2[temp.second]);
            if(temp.first + 1 < nums1.size()) pq.emplace(temp.first + 1, temp.second);
            if(temp.first == 0 && temp.second + 1 < nums2.size()) pq.emplace(temp.first, temp.second + 1);
        }
        return ans;   
    }
};