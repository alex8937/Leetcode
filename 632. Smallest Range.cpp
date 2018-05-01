class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> index(nums.size(), 0);
    int global_left = 100000, global_right = -100000;
    for (int i = 0; i < nums.size(); ++i) {
      pq.emplace(nums[i][0], i);
      global_left = min(global_left, nums[i][0]);
      global_right = max(global_right, nums[i][0]);
    }
    auto local_max = global_right;
    while (index[pq.top().second] + 1 < nums[pq.top().second].size()) {
      auto idx = pq.top().second;
      pq.pop();
      index[idx]++;
      int next_val = nums[idx][index[idx]];
      pq.emplace(next_val, idx);
      local_max = max(local_max, next_val);
      if (local_max - pq.top().first < global_right - global_left) {
        global_left = pq.top().first;
        global_right = local_max;
      }
    }
    return vector<int>{global_left, global_right};
  }
};