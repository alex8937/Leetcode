class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int localmin = INT_MAX;
        int maxpro = 0;
        for(auto& p : prices) {
            localmin = min(p, localmin);
            maxpro = max(maxpro, p - localmin);
        }
        return maxpro;
    }
};