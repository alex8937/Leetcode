class Solution {
public:
    int myAtoi(string str) {
        bool neg = false;
        long ans = 0;
        int pos = str.find_first_not_of(' ');
        if(pos == -1) return 0;
        if(str[pos] == '-' || str[pos] == '+') neg = (str[pos++] == '-');
        while(pos < str.size() && isdigit(str[pos])) {
            int val = str[pos++] - '0';
            ans = ans * 10 + (neg? -val : val);
            if(ans > INT_MAX) return INT_MAX;
            if(ans < INT_MIN) return INT_MIN;
        }
        return ans;
    }
};