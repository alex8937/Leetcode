int maxProfit(vector<int>& prices) {
  // O(n) space
	if (prices.size() == 0) return 0;
	vector<int> buy(prices.size(), -prices[0]), sell(prices.size(), 0), rest(prices.size(), 0);
	for (int i = 1; i < prices.size(); ++i) {
		buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);
		sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
		rest[i] = max(sell[i - 1], rest[i - 1]);
	}
	return max(sell.back(), rest.back());
}

==================


int maxProfit(vector<int>& prices) {
  // O(1) space
	int buy = INT_MIN, sell = 0, rest = 0, rest_last = 0;
	for (auto p : prices) {
		rest_last = rest;
		rest = max(rest, sell);
		sell = max(sell, buy + p);
		buy = max(buy, rest_last - p);
	}
	return max(sell, rest);
}