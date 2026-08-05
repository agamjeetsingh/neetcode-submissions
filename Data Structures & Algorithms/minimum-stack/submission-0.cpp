class MinStack {
public:
    MinStack() {
        // 3, 1, 2, 0
        // [] -> [3] -> [1] -> [1] -> [1, 0]
        
    }

    stack<int> st;
    stack<int> minSt;
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || minSt.top() >= val) {
            minSt.push(val);
        }
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if (minSt.top() == top) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
