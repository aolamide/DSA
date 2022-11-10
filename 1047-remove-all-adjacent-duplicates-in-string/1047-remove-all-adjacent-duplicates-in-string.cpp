class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sk;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(!sk.empty() && sk.top() == s[i]) {
                sk.pop();
                continue;
            }
            sk.push(s[i]);
        }
        
        string result = "";
        
        while(!sk.empty()) {
            result += sk.top();
            sk.pop();
        }
        
        return result;
    }
};