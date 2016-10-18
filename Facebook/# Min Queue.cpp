#include <queue>
#include <iostream>

using namespace std;

class Min_Queue {
private:
	queue<int> store;
	queue<int> qu_min;
public:
	Min_Queue(){
		
	}
	void push(int x) {
		store.push(x);
		if(!qu_min.empty() && x < qu_min.front()) {
			while(!qu_min.empty()) qu_min.pop();
 		}
		qu_min.push(x);
	}
	
	void pop() {
		int pop_val = store.front();
		store.pop();
		if(pop_val == qu_min.front()) qu_min.pop();
	}
	
	int get_min() {
		return qu_min.front();
	}
	
};

int main() {
	Min_Queue* mq = new Min_Queue();
	mq -> push(7);	
	mq -> push(5);
	mq -> push(4);
	mq -> push(6);	
	mq -> push(8);
	cout << mq -> get_min() << endl;	
	mq -> pop();		
	cout << mq -> get_min() << endl;		
	mq -> pop();		
	cout << mq -> get_min() << endl;		
	mq -> pop();		
	cout << mq -> get_min() << endl;		
	mq -> pop();		
	cout << mq -> get_min() << endl;		
	mq -> pop();				
}








