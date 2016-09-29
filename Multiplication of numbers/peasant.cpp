#include <iostream>

using namespace std;

int multiplication(int a, int b) {
	int ans = 0;
	while(a) {
		if(a & 1 != 0) ans += b;
		a >>= 1;
		b <<= 1;
	}
	return ans;
}

int main() {
	cout << multiplication(35, 101);
}