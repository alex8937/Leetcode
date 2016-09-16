class Solution {
public:
    inline bool compatible(char a, char b) {
        if(a == b) {
            if(a == '0' || a == '1' || a == '8') return true;
        }
        else {
            if((a == '6' && b == '9') || (a == '9' && b == '6')) return true;
        }
        return false;
    }
    bool isStrobogrammatic(string num) {
        int start = 0, end = num.size() - 1;
        while(start <= end) {
            if(compatible(num[start], num[end])) {
                start++;
                end--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};