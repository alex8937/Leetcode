//ver1 : divide and conquer

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  return getSkyline(buildings, 0, int(buildings.size()) - 1);
}


vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings, int start, int end) {
  vector<pair<int, int>> ans;
  if(start > end) return ans;
  if(start == end) {
    ans.emplace_back(buildings[start][0], buildings[start][2]);
    ans.emplace_back(buildings[start][1], 0);
    return ans;
  }
  int mid = start + (end - start) / 2;
  auto s1 = getSkyline(buildings, start, mid);
  auto s2 = getSkyline(buildings, mid + 1, end);
  return merge(s1, s2);
}


vector<pair<int, int>> merge(vector<pair<int, int>>& s1, vector<pair<int, int>>& s2) {
  vector<pair<int, int>> ans;
  int i = 0, j = 0, y1 = 0, y2 = 0;
  while(i < s1.size() && j < s2.size()) {
    int x1 = s1[i].first, x2 = s2[j].first;
    int x = min(x1, x2);
    if(x1 == x) y1 = s1[i++].second;
    if(x2 == x) y2 = s2[j++].second;
    int y = max(y1, y2);
    if(ans.size() == 0 || y != ans.back().second) ans.emplace_back(x, y);
  }
  while(i < s1.size()) ans.emplace_back(s1[i++]);
  while(j < s2.size()) ans.emplace_back(s2[j++]);
  return ans;
}

// ver2: priority_queue
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  priority_queue<pair<int, int>> qu;
  vector<pair<int, int>> ans;
  int cur = 0;
  while(cur < buildings.size() || !qu.empty()) {
    int x;
    if(cur == buildings.size() || !qu.empty() && qu.top().second < buildings[cur][0]) {
      x = qu.top().second;
      while(!qu.empty() && qu.top().second <= x) qu.pop();
    }
    else {
      x = buildings[cur][0];
      while(cur < buildings.size() && buildings[cur][0] <= x) {
        qu.emplace(buildings[cur][2], buildings[cur][1]);
        cur++;
      }
    }
    int y = (!qu.empty())? qu.top().first : 0;
    if(ans.empty() || y != ans.back().second) ans.emplace_back(x, y);
  }
  return ans;
}
 