class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        if(st.empty() == false) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = (long long) val;
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else{
            if(value> mini) st.push(value);
            else{
                long long newVal = 2 * value - mini;
                st.push(newVal);
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x<mini) mini = 2*mini - x;
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(x<mini) return mini;
        return (int)x;
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */