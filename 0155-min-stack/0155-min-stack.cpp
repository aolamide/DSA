class MinStack {
public:
    vector<pair<int, int>> stack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(!stack.size()) {
            stack.push_back({val, val});
            return;
        }
        int min = getMin();
        if(min < val) {
            stack.push_back({val, min});
        } else {
            stack.push_back({val, val});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1].first;
    }
    
    int getMin() {
        return stack[stack.size() - 1].second;
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