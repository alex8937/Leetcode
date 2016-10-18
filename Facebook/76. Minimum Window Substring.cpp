class Solution {
public:
    string minWindow(string s, string t) {
    //1. Use two pointers: start and end to represent a window.
    //2. Move end to find a valid window.
    //3. When a valid window is found, move start to find a smaller window.
        vector<int> dict(128,0);
        for(auto c: t) dict[c]++;
        int cnt = t.size(), start = 0, end = 0, len = s.size() + 1, head = 0;
        while(end < s.size()) {
            if(dict[s[end]] > 0) {
                cnt--;
            }
            dict[s[end]]--;
            end++;
            while(cnt == 0) {
                if(end - start < len) {
                    len = end - start;
                    head = start;
                }
                dict[s[start]]++;
                if(dict[s[start]] > 0) cnt++;
                start++;
            }
        }
        return (len > s.size())? "":s.substr(head, len);        
    }
};