int maxProfit(int k, vector<int>& prices) {
	if (k == 0) return 0;
	if (k > prices.size() / 2) {
		int ans = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if(prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
		}
		return ans;
	}
	vector<int> hold(k, INT_MIN), release(k, 0);
	for (auto p : prices) {
		for (int i = k - 1; i >= 0; --i) {
			release[i] = max(release[i], hold[i] + p);
			hold[i] = max(hold[i], ((i == 0) ? 0 : release[i - 1]) - p);
		}

	}
	return release.back();
}