class Solution {
public:
    bool isValid(string s) {
      //ver 1
        unordered_map<char, char> dict({{'(', ')'}, {'[', ']'}, {'{', '}'}});
        stack<char> st;
        for(char c : s) {
            if(dict.count(c)) st.push(dict[c]);
            else if(!st.empty() && st.top() == c) st.pop();
            else return false;
        }
        return st.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
      //ver 2
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if(st.empty()) return false;
                if((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') || (st.top() == '{' && c == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};