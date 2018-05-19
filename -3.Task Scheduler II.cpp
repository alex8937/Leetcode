#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;
int task_process(string tasks, int cooldown) {
	unordered_map<char, int> dict;
	int cur = 1;
	for(auto c : tasks) {
		if(dict.count(c)) cur = max(cur, dict[c] + 1 + cooldown);
		dict[c] = cur;
		cur++;
	}
	return cur - 1;
}


int main() {
	cout << task_process("ABCD", 3) << endl;
	cout << task_process("ABAD", 3) << endl;
	cout << task_process("AAAA", 3) << endl;
	cout << task_process("ABCACBDA", 4) << endl;