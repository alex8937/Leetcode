#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
	//version 1: using 2d array
	//dp[i][j] represents first i pack to get size j
	//dp[i][0] = true;  dp[0][A[0]] = true;
	//dp[i][j] = dp[i - 1][j] not use ith pack
	//				|| dp[i - 1][j - A[i]]  use ith pack
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        vector<vector<bool>> dp(A.size(), vector<bool>(m + 1, false));
        int ans = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j <= m; ++j) {
                if(j == 0) dp[i][j] = true;
								else if(i == 0) dp[i][A[i]] = true;
                else dp[i][j] = dp[i - 1][j] || (j >= A[i] && dp[i - 1][j - A[i]]);
                if(dp[i][j]) ans = max(ans, j);
            }
        }
        return ans;
    }
    
};

class Solution2 {
public:
	//version 2: using 1d array
	// reverse j
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        int ans = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = m; j >= 0; --j) {
								if(i == 0) dp[A[i]] = true;
                else dp[j] = dp[j] || (j >= A[i] && dp[j - A[i]]);
                if(dp[j]) ans = max(ans, j);
            }
        }
        return ans;
    }
    
};

int main() {
	Solution1 s;
	vector<int> pack = {2,3,4,5};
	int m = 13;
	cout << s.backPack(m, pack);
}

