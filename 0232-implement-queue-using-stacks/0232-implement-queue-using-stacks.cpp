class MyQueue {
private:
    void moveToStack2() {
        if(!stack2.empty()) return; //keep returning from stack2 until it is empty
        
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    stack<int> stack1;
    stack<int> stack2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        int x = peek();
        stack2.pop();
        return x;
    }
    
    int peek() {
        moveToStack2();
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */