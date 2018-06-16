// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        char temp[4] = "";
        for(int i = 0; i < n; i += 4) {
            int count = read4(temp);
            count = min(n - ans, count);
            for(int j = 0; j < count; ++j) {
                buf[ans++] = temp[j];
            }
            if(count < 4) break;
        }
        return ans;
    }
};