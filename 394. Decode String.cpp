class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, int>> repeat_starts;
        string ret;
        int times = 0;
        for(auto& c : s) {
          if(c == '[') {
            repeat_starts.push(make_pair(times - 1, ret.size()));
            times = 0;
          }
          else if(c == ']') {
            auto repeat_info = repeat_starts.top();
            auto repeat_content = ret.substr(repeat_info.second);
            for(int k = 1; k <= repeat_info.first; ++k) {
              ret.append(repeat_content);
            }
            repeat_starts.pop();
          }
          else if(isdigit(c)){
            times = times * 10 + c - '0';
          }
          else {
            ret.push_back(c);
          }
        }
        return ret;
    }
};
