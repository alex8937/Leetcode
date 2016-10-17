class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return tens[0];
				return help(num).substr(1);
    }
private:
    const vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};    
    string help(int n) {
        if(n >= 1000000000) return help(n / 1000000000) + " Billion" + help(n % 1000000000);
        else if(n >= 1000000) return help(n / 1000000) + " Million" + help(n % 1000000);
        else if(n >= 1000) return help(n / 1000) + " Thousand" + help(n % 1000);
        else if(n >= 100) return help(n / 100) + " Hundred" + help(n % 100);
        else if(n >= 20) return " " + tens[n / 10] + help(n % 10);
        else if(n >= 1) return " " + digits[n];
        else return "";
    }
};