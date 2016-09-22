class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1;  // The leftmost boundry (not included) for the substing
        vector<int> dict(256, -1);
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            left = max(left, dict[s[i]]);
            ans = max(i - left ,ans);
            dict[s[i]] = i;            
        }
        return ans;
    }
};