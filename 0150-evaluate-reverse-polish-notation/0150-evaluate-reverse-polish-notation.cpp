class Solution {
public:
    void evaluateOp(stack<long>& s, string op) {
        long num1 = s.top();
        s.pop();
        long num2 = s.top();
        s.pop();
        long result;
        if(op == "+") result = num1 + num2;
        else if(op == "*") result = num1 * num2;
        else if(op == "/") result = num2 / num1;
        else result = num2 - num1;
        
        s.push(result);
    }
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        unordered_set<string> ops = {"+", "-", "/", "*"}; 
        
        for(string val : tokens) {
            if(!ops.count(val)) {
                s.push(stoi(val));
            } else {
                evaluateOp(s, val);
            }
        }
        
        return (int) s.top();
    }
};