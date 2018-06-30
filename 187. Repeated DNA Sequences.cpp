vector<string> findRepeatedDnaSequences(string s) {
	if (s.size() <= 10) return vector<string>();
	unordered_map<char, int> mapping{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
	unordered_map<int, int> dict;
	vector<string> ans;
	int encode = 0;
	for (int i = 0; i < s.size(); ++i) {
		encode = ((encode << 2) | mapping[s[i]]) & 0x000FFFFF;
		if (i >= 9) {
			if (dict[encode] == 1) {
				ans.push_back(s.substr(i - 9, 10));
			}
			dict[encode]++;
		}
	}
	return ans;
}