class Solution {
public:
    int calculate(string s) {
        stack<int> operators({1});
        
        int result = 0, num = 0;
        
        int sign = 1;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                result += num * sign * operators.top();
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == ')') operators.pop();
                if (c == '(') {
                    operators.push(operators.top() * sign);
                    
                    sign = 1;
                }
            }
        }
        result += num * sign * operators.top();
        
        return result;
    }
};