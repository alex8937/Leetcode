class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return true;
        if(wordDict.empty()) return false;
        
        int maxlen = 0;
        for(auto s :  wordDict) {
            maxlen = max(maxlen, int(s.size()));
        }
        
        //dp[x] represents s.substr(0, x - 1) matching
        // match(0, x - 1) = match(0, x - len - 1) && find(x - len, x - 1)
        //dp[x] = dp[x] || dp[x - len] && find(substr(x - len, len)) 
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int global = 1; global < dp.size(); ++global) {
            for(int len = 1; len <= global && len <= maxlen;  ++len) {
                dp[global] = dp[global] || (dp[global - len] && wordDict.count(s.substr(global - len, len)));
            }
        }
        return dp.back();
    }
};