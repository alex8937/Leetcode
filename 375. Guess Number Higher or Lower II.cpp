class Solution {
public:
	//Top to bottom
    int getMoneyAmount(int n) {
        vector<vector<int>> dict(n + 1, vector<int>(n + 1, -1));
        return help(1, n, dict);
    }
    int help(int low, int high, vector<vector<int>>& dict) {
        if(low >= high) return 0;
        if(dict[low][high] != -1) return dict[low][high];
        dict[low][high] = INT_MAX;
        for(int guess = low; guess <= high; ++guess) {
            int left = help(low, guess - 1, dict);
            int right = help(guess + 1, high, dict);
            dict[low][high] = min(dict[low][high], guess + max(left, right));
        }
        return dict[low][high];
    }
};


class Solution {
public:
	//Bottom to top
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int end = 2; end <= n; ++end) {
            for(int start = end - 1; start >= 1; --start) {
                dp[start][end] = INT_MAX;
                for(int guess = start; guess < end; ++guess) {
                    dp[start][end] = min(dp[start][end], guess + max(dp[start][guess - 1], dp[guess + 1][end]));
                }
            }
        }
        return dp[1][n];
    }
};