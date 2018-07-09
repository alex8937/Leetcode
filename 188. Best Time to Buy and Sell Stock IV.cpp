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


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size() / 2) {
            int ans = 0;
            for(int i = 1; i < prices.size(); ++i) {
                if(prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
            }
            return ans;
        }
        else {
            vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
            for(int i = 1; i <= k; ++i) {
                int local_max = INT_MIN;
                for(int j = 0; j < prices.size(); ++j) {
                    dp[i][j] = max(dp[i][j - 1], prices[j] + local_max);
                    local_max = max(local_max, dp[i - 1][j] - prices[j]);
                }
            }
            return dp.back().back();
        }
    }
};