int maxProfit(vector<int>& prices) {
  // O(k * n) space
	if (prices.size() == 0) return 0;
	vector<int> buy1(prices.size(), -prices[0]), buy2(prices.size(), -prices[0]), sell1(prices.size(), 0), sell2(prices.size(), 0);
	for (int i = 1; i < prices.size(); ++i) {
		buy1[i] = max(buy1[i - 1], - prices[i]);
		sell1[i] = max(sell1[i - 1], buy1[i - 1] + prices[i]);
		buy2[i] = max(buy2[i - 1], sell1[i - 1] -prices[i]);
		sell2[i] = max(sell2[i - 1], buy2[i - 1] + prices[i]);
	}
	return sell2.back();
}

======================

int maxProfit(vector<int>& prices) {
  // O(n) space
	int hold1 = INT_MIN, hold2 = INT_MIN, release1 = 0, release2 = 0;
	for (auto p : prices) {
		release2 = max(release2, hold2 + p);
		hold2 = max(hold2, release1 - p);
		release1 = max(release1, hold1 + p);
		hold1 = max(hold1, - p);
	}
	return release2;
}
