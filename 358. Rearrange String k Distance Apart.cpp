class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) return s;
        unordered_map<char, int> dict;
        int len = s.size();
        for(char c : s) {
            dict[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it : dict) pq.emplace(it.second, it.first);
        string ans;
        while(!pq.empty()) {
            vector<pair<int, char>> cache;
            int count = min(k, len);
            for(int i = 0; i < count; ++i) {
                if(pq.empty()) return "";
                auto head = pq.top();
                pq.pop();
                if(head.first > 1) cache.emplace_back(head.first - 1, head.second);
                ans.push_back(head.second);
                len--;
            }
            for(auto it : cache) pq.emplace(it);
        }
        return ans;
    }
};