class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> regularStk;
    stack<int> minStk;
    
    MinStack() {
        
    }
    
    void push(int x) {
        regularStk.push(x);
        
        if(minStk.empty())
            minStk.push(x);
        else
            minStk.push(min(minStk.top(), x));
        
    }
    
    void pop() {
        regularStk.pop();
        minStk.pop();
    }
    
    int top() {
        return regularStk.top();
    }
    
    int getMin() {
        return minStk.top();
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