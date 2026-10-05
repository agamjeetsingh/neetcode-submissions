class MinStack {
public:
    MinStack() {
        
    }

    stack<int> s;
    stack<int> ms;
    
    void push(int val) {
        s.push(val);
        if (ms.empty() || ms.top() >= val) ms.push(val);
    }
    
    void pop() {
        int val = s.top(); s.pop();
        if (ms.top() == val) ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
