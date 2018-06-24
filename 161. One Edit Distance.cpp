bool replace(string s, string t) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != t[i]) return s.substr(i + 1) == t.substr(i + 1);
	}
	return false;
}

bool remove(string s, string t) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != t[i]) return s.substr(i + 1) == t.substr(i);
	}
	return false;
}

bool isOneEditDistance(string s, string t) {
	if (s.size() == t.size()) return replace(s, t);
	if (s.size() == t.size() + 1) return remove(s, t);
	if (s.size() == t.size() - 1) return remove(t, s);
	return false;
}
