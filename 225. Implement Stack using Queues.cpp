class Stack {
private:
    queue<int> q1, q2;
public:
    // Push element x onto stack.
    void push(int x) {
        auto& full = (q1.empty()) ? q2 : q1;
        full.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        auto& full = (q1.empty()) ? q2 : q1;
        auto& emp = (!q1.empty()) ? q2 : q1;
        while(full.size() != 1) {
            emp.push(full.front());
						full.pop();
        }
        full.pop();
    }

    // Get the top element.
    int top() {
        auto& full = (q1.empty()) ? q2 : q1;
        return full.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};