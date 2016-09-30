#include <iostream>

using namespace std;

int Josephus(int n, int k) {
	int cur = 0; // f(1) = 0
	for(int m = 2; m <= n; ++m) {
		cur = (cur + k) % (m - 1); // f(n) = (f(n - 1) + k) % (n - 1)
	}
	return cur;
}

int main() {
	cout << Josephus(5,3);
}