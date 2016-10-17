class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size(), '0');
        for(int i = num1.size() - 1; i >= 0; --i) {
            int n1 = num1[i] - '0';
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; --j) {
                int n2 = num2[j] - '0';
                int sum = ans[i + j + 1] - '0';
                sum += n1 * n2 + carry;
                ans[i + j + 1] = sum % 10 + '0';
                carry = sum / 10;
            }
            if(carry) ans[i] += carry;
        }
        auto pos = ans.find_first_not_of('0');
        if(pos == -1) return "0";
        else return ans.substr(pos);
    }
};