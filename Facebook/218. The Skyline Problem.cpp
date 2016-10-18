class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ans;
        priority_queue<pair<int, int>> qu;
        int cur = 0; 
        while(cur < buildings.size() || !qu.empty()) {
            int next;
            if(cur == buildings.size() || !qu.empty() &&  qu.top().second < buildings[cur][0]) {
                next = qu.top().second;
                while(!qu.empty() && qu.top().second <= next) qu.pop();
            }
            else {
                next =  buildings[cur][0];
                while(cur < buildings.size() && buildings[cur][0] == next) {
                    qu.emplace(buildings[cur][2], buildings[cur][1]);
                    cur++;
                }
            }
            int height = (!qu.empty())? qu.top().first : 0;
            if(ans.empty() || ans.back().second != height) ans.emplace_back(next, height);
        }
        return ans;
    }
};