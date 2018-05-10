class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ans;
		vector<int> cand;
		helper(ans, cand, n);
		return ans;
	}
	void helper(vector<vector<string>>& ans, vector<int>& cand, int n) {
		if (cand.size() == n) {
			vector<string> res(n, string(n, '.'));
			for (int i = 0; i < cand.size(); ++i) res[i][cand[i]] = 'Q';
			ans.push_back(res);
		}
		for (int i = 0; i < n; ++i) {
			if (!valid(cand, i)) continue;
			cand.push_back(i);
			helper(ans, cand, n);
			cand.pop_back();
		}
	}
	bool valid(vector<int>& cand, int k) {
		for (int i = 0; i < cand.size(); ++i) {
			if (k == cand[i] || abs(k - cand[i]) == abs(int(cand.size()) - i)) return false;
		}
		return true;
	}
};