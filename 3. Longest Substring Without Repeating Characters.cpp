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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[128] = {0};
        int start = 0, end = 0, ans = 0;
        while(end < s.size()) {
            dict[s[end]]++;           
            while(dict[s[end]] > 1) {
                dict[s[start]]--;
                start++;
            }
            end++;
            ans = max(ans, end - start);
        }
        return ans;
    }
};