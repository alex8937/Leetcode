// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char temp[4] = "";
    int offset = 0;
    int len = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        while(ans < n) {
            if(offset != len) {
                buf[ans++] = temp[offset++];
            }
            else {
                offset = 0;
                len = read4(temp);
                if(len == 0) break;                
            }
            
        }
        return ans;
    }
};