class Solution {
public:
    vector<int> grayCode(int n) {
		// version 1: pattern observation
        if(n == 0) return {0};
        auto ans = grayCode(n - 1);
        for(int i = ans.size() - 1; i >= 0; --i) {
            ans.push_back(ans[i] | (1 << (n - 1))); // patch 1 in the front
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
		// version 2: gray code mapping
		vector<int> ans(1<<n, 0);
		for(int i = 0; i < ans.size(); ++i) {
			ans[i] = i ^ (i >> 1);
		}
		return ans;
    }
};


