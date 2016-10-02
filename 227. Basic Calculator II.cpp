class Solution {
public:
    int calculate(string s) {
        long result = 0, temp = 0;
        char op = '+';
        for(int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) {
                int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                if(op == '+' || op == '-') {
                    result += temp;
                    temp = (op == '+')? num : -num;
                }
                else if(op == '*') {
                    temp *= num;
                }
                else {
                    temp /= num;
                }
            }
            if(s[i] != ' ') op = s[i];
        }
        return result + temp;
    }
};