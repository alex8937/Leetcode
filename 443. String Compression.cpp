class Solution {
public:
    int compress(vector<char>& chars) {
        int end = 0, pos = 0;
        while(end < chars.size()) {
            int rec = chars[end++];
            int cnt = 1;
            while(i < chars.size() && chars[end] == rec) {
                cnt++;
                end++;
            }
            chars[pos++] = rec;
            if(cnt != 1) {
                for(auto c : to_string(cnt)) {
                    chars[pos++] = c;
                }
            }
        }
        return pos;
    }
};