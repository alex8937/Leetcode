class Solution {
public:
    int hIndex(vector<int>& citations) {
    // version1: sort
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i = 0; i < citations.size(); ++i) {
            if(citations[i] <= i) return i;
        }
        return citations.size(); 
    // version2: count
        int len = citations.size();
        vector<int> dict(len + 1, 0);
        for(auto c : citations) {
            if(c >= len) dict[len]++;
            else dict[c]++;
        }
        int cnt = 0;
        for(int i = len; i >= 0; --i) {
            cnt += dict[i];
            if(cnt >= i) return i;
        }
        return 0;
        
    }
};