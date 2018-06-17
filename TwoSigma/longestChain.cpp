# include<iostream>
# include<unordered_map>
# include<vector>
# include<algorithm>
using namespace std;

int longestChain(vector<string>& words) {
  auto cmp = [](string& s1, string& s2){return (s1.size() < s2.size()) || (s1.size() == s2.size() && s1 < s2);};  
  sort(words.begin(), words.end(), cmp);
  unordered_map<string, int> dict;
  int ans = 0;
  for(auto word : words) {
    if(dict.count(word)) continue;
    dict[word] = 1;
    for(int i = 0; i < word.size(); ++i) {
      auto temp = word.substr(0, i) + word.substr(i + 1);
      if(dict.count(temp)) {
        dict[word] = max(dict[word], 1 + dict[temp]);
      }
    }
    ans = max(ans, dict[word]);
  }
  return ans;
}

int main() {
  vector<string> w1({"b", "bca", "ba", "bda", "bdca", "a"});
  vector<string> w2({"b"});
  vector<string> w3;
  vector<string> w4({"b","ba","bca","bdca","ebdca","b"});
  cout << longestChain(w1) << endl;
  cout << longestChain(w2) << endl;  
  cout << longestChain(w3) << endl;
  cout << longestChain(w4) << endl;  
  return 0;
}