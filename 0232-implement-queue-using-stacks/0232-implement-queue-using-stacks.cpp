class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() { }
    
    void push(int x) {
        // Move all elements from st1 to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        // Push the new element onto st1
        st1.push(x);
        // Move elements back to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if (st1.empty()) {
            throw runtime_error("Queue is empty, cannot pop");
        }
        int val = st1.top();
        st1.pop();
        return val;
    }
    
    int peek() {
        if (st1.empty()) {
            return 1;
        }
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};
