class Solution {
public:
  bool isNumber(string s) {
    bool ans = true;
      int index = 0;
    procE(s, ans, index);
    return ans;
  }

  void procE(const string& s, bool& ans, int& i) {
    procSpace(s, ans, i);
    procBase(s, ans, i);
    procExp(s, ans, i);
    procSpace(s, ans, i);
    procEnd(s, ans, i);
  }

  void procSpace(const string& s, bool& ans, int& i) {
    while (i < s.size() && s[i] == ' ') i++;
  }

  void procSign(const string& s, bool& ans, int& i) {
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) i++;
  }

  void procBase(const string& s, bool& ans, int& i) {
    procSign(s, ans, i);
    if (i < s.size() && isdigit(s[i])) {
      procDigit(s, ans, i);
      if (i < s.size() && s[i] == '.') {
        i++;
        if(isdigit(s[i])) procDigit(s, ans, i);
      }
    }
    else if (i < s.size() && s[i] == '.') {
      i++;
      procDigit(s, ans, i);
    }
    else {
      ans = false;
    }
  }

  void procDigit(const string& s, bool& ans, int& i) {
    if (i < s.size() && isdigit(s[i])) {
      while (i < s.size() && isdigit(s[i])) i++;
    }
    else {
      ans = false;
    }
  }

  void procExp(const string& s, bool& ans, int& i) {
    if (i < s.size() && s[i] == 'e') {
      i++;
          procSign(s, ans, i);
      procDigit(s, ans, i);
    }
  }

  void procEnd(const string& s, bool& ans, int& i) {
    if (i != s.size()) ans = false;
  }
};