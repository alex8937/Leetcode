#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <iostream>
#include <sstream>
#include <list>

using namespace std;
/* Proof of correctness:
For number in reservoir is less than k;
if new comes, accept;
else
We have k elements in reservoir, and Nth element comes;
P_Accept_Nth = k/N;
Given Accept_Nth, remove a random element existed in reservoir and add Nth. 
P_Accept_i		where 1 <= i <= N - 1
P_Accept_i = k/(N - 1) * (1 - k/N * 1/k) = k/N
						----------		-------------
						exist in res   not being removed
						last step      this step
*/
void reservoir_sampling(list<string>& pool, string cur, int k, int N) {
	if(pool.size() < k) {
		pool.push_back(cur);
	}
	else {
		int randgen = rand() % N + 1; // get a randU 1 to N
		if(randgen <= k) {
			int del_index = rand() % k;  // get a randU 0 to k - 1
			pool.erase(next(pool.begin(), del_index));
			pool.push_back(cur);
		}
	}
}

int main() {
	stringstream ss("1 2 3 4 5 6 7 8 9 10 11 12");
	string temp;
	list<string> pool;
	int k = 5, N = 1;
	srand (time(NULL));
	while(ss >> temp) {
		reservoir_sampling(pool, temp, k, N++);
		for(auto str : pool) cout << str << " ";
		cout << endl;
	}
}