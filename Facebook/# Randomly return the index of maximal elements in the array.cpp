#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <iostream>
#include <vector>
using namespace std;

int random_max_index(vector<int> nums) {
	if(nums.empty()) return -1;
	int cur_max = nums[0];
	int index = 0;
	for(int i = 0; i < nums.size(); ++i) {
		if(nums[i] > cur_max) {
			cur_max = nums[i];
			nums[0] = i;
			index = 1;
		}
		else if(nums[i] == cur_max) {
			nums[index++] = i;
		}
	}
	return nums[rand() % index];
}

int main() {
	vector<int> nums = {3, 5, 4, 5, 5};
	srand (time(NULL));
	cout << random_max_index(nums);
}