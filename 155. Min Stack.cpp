class MinStack {
private:
    stack<int> store;
    stack<int> store_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        store.push(x);
        if(store_min.empty() || x <= store_min.top()) store_min.push(x);
    }
    
    void pop() {
        if(store_min.top() == store.top()) store_min.pop();
        store.pop();
    }
    
    int top() {
        return store.top();
    }
    
    int getMin() {
        return store_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */