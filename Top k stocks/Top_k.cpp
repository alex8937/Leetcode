#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

// use set to sort stock by its price;
// use hash_table to link stock name with the set iterator;

// update O(log n)
// get top k O(k)


class board{
	public:
		int k;
		unordered_map<string, set<pair<int, string>> :: iterator> store;
		set<pair<int, string>> dict;

		void set_k(int _k) {
			k = _k;
		}
		void update(string c, int n) {
			if(!store.count(c)) {
				dict.insert(make_pair(n, c));
				store[c] = dict.find(make_pair(n, c));
			}
			else {
				set<pair<int, string>> :: iterator target = store[c];
				dict.erase(target);
				dict.insert(make_pair(n, c));
				store[c] = dict.find(make_pair(n, c));				
			}
		}
		
		void topk() {
			int cnt = 0;
			for(auto it = dict.rbegin(); it != dict.rend(); ++it) {
				cout << it -> second <<" "<<it -> first << " ";
				if(++cnt == k) break;
			}
			cout << endl;
		} 

};

int main() {
	board* a = new board;
	a -> set_k(2);
	a -> update("a",4.0);
	a -> update("b",5.0);
	a -> update("b",3.0);
	a -> update("c",10.0);
	a -> update("a",1.0);
	a -> topk();
}