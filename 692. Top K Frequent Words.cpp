class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        for(auto word : words) {
            dict[word]++;
        }
        auto cmp = [](pair<int, string>& p, pair<int, string>& q) {return p.first < q.first || (p.first == q.first && p.second > q.second);};
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for(auto it : dict) {
            pq.emplace(it.second, it.first);
        }
        vector<string> ans;
        for(int i = 0; i < k; ++i) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};