#include <vector>
#include <iostream>
using namespace std;


int findmax_1D(vector<int> nums) {
	int local = nums[0];
	int ans = nums[0];
	for(int i = 1; i < nums.size(); ++i) {
		local = max(nums[i], local + nums[i]);
		ans = max(ans, local);
	}
	return ans;
}

int findmax_2D(vector<vector<int>> matrix) {
	int ans = matrix[0][0];
	for(int i = 1; i < matrix.size(); ++i) {
		for(int j = 0; j < matrix[i].size(); ++j) {
			matrix[i][j] += matrix[i - 1][j];
		}
	}
	for(int i = 0; i < matrix.size(); ++i) {
		for(int k = 0; k <= i; ++k) {
			vector<int> dummy;
			for(int j = 0; j < matrix[0].size(); ++j) {
				int subtract = (k == 0)? 0 : matrix[k - 1][j];
				dummy.push_back(matrix[i][j] - subtract);
			}
			ans = max(ans, findmax_1D(dummy));
		}
	}
	return ans;
}


int main() {
	vector<vector<int>> nums = {{1 ,  2, -1, -4, -20},
															{-8, -3,  4,  2,   1},
															{3,   8, 10,  1,   3},
															{-4, -1,  1,  7,  -6}};
	cout << findmax_2D(nums);
}