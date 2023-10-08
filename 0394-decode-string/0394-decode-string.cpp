class Solution {
public:
    string decodeString(string st) {
        stack<char> s;
        for(char ch : st) {
            if(ch != ']') s.push(ch);
            
            else {
                string curr = "";
                while(s.top() != '[') {
                    curr = s.top() + curr;
                    s.pop();
                }
                s.pop(); //for [
                
                string num = "";
                while(!s.empty() && isdigit(s.top())) {
                    num = s.top() + num;
                    s.pop();
                } 
                
                int k = stoi(num);
                
                while(k--) {
                    for(int p = 0; p < curr.size(); p++) {
                        s.push(curr[p]);
                    }
                }
            }
        }
        
        string result = "";
        while(!s.empty()) {
            result = s.top() + result;
            s.pop();
        }
        
        return result;
    }
};