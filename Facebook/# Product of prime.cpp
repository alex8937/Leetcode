#include <vector>
#include <iostream>

using namespace std;



void help(int cand, const vector<int>& primes, vector<int>& numbers, int index) {
	cout<< cand << " ";
	for(int i = index; i < primes.size(); ++i) {
		if(numbers[i] > 0) {
			numbers[i]--;
			if(numbers[i] == 0) help(cand * primes[i], primes, numbers, i + 1);
			else help(cand * primes[i], primes, numbers, i);
			numbers[i]++;
		}
	}
}

void product(vector<int> primes, vector<int> numbers) {
	if(primes.empty()) return;
	help(1, primes, numbers, 0);
}

int main() {
	vector<int> primes = {2, 3, 5};
	vector<int> nums = {1, 2, 1};
	product(primes, nums);
}