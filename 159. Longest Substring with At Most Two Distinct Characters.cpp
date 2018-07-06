class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, end = 0, cnt = 0, ans = 0;
        int dict[128] = {0};
        while(end < s.size()) {
            if(++dict[s[end]] == 1) cnt++;
            end++;
            while(cnt > 2) {
                if(--dict[s[start]] == 0) cnt--;
                start++;
            }
    
            ans = max(ans, end - start);
        }
        return ans;
    }
};