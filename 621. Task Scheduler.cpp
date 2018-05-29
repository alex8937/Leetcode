class Solution {
  //ver 1: O(n)
public:
    int leastInterval(vector<char>& tasks, int n) {
        int dict[26] = {0};
        for(int t : tasks) dict[t - 'A']++;
        sort(dict, dict + 26);
        int i = 25;
        while(i >= 0 && dict[i] == dict[25]) i--;
        return max(int(tasks.size()), (dict[25] - 1) * (n + 1) + 25 - i);
    }
};


class Solution {
public:
  //ver 2: O(tasks.size() * logk)
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> dict;
        for(auto t : tasks) dict[t]++;
        priority_queue<pair<int, char>> pq;
        for(auto it : dict) pq.emplace(it.second, it.first);
        int ans = 0, k = n + 1;
        while(!pq.empty()) {
            vector<pair<int, char>> cache;
            for(int i = 0; i < k && !pq.empty(); ++i) {
                auto head = pq.top();
                pq.pop();
                cache.emplace_back(head.first - 1, head.second);
            }
            for(auto it : cache) {
                if(it.first > 0) pq.emplace(it);
            }
            ans += (pq.empty())? int(cache.size()) : k;
        }
        return ans;
    }
};