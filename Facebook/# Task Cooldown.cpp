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

int task_rearrange(string tasks, int cooldown) {
	unordered_map<char, int> dict;
	string ans;
	for(char c : tasks) {
		dict[c]++;
	}
	priority_queue<pair<int, char>> pq;
	for(auto it : dict) {
		pq.emplace(it.second, it.first);
	}
	int cur = 1;
	while(!pq.empty()) {
		vector<pair<int, char>> cache;
		int count = cooldown + 1;
		while(count > 0) {
			if(pq.empty()) {
				if(!cache.empty()) ans += string(count, '.');
				if(!cache.empty()) cur += count;
				break;
			}
			auto temp = pq.top();
			pq.pop();
			ans.push_back(temp.second);
			if(--temp.first > 0) cache.push_back(temp);
			cur++;
			count--;
		}
		for(auto it : cache) pq.push(it);
	}
	cout << ans << endl;
	return cur - 1;
}

int main() {
	cout << task_process("ABCD", 3) << endl;
	cout << task_process("ABAD", 3) << endl;
	cout << task_process("AAAA", 3) << endl;
	cout << task_process("ABCACBDA", 4) << endl;
	
	cout << task_rearrange("AAAA", 3) << endl;
	cout << task_rearrange("ABABABAB", 3) << endl;
}