class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> parStack; //stack for parentheses index
        vector<char> chars(s.begin(), s.end());
        
        for(int i = 0; i < chars.size(); i++) {
            if(chars[i] == '(') {
                parStack.push_back(i);
            } else if(chars[i] == ')') {
                if(!parStack.size()) {
                    chars[i] = '\0';
                } else {
                    parStack.pop_back();
                }
            }
        }
        
        //remove unmatched opening parentheses
        while(parStack.size()) {
            int idx = parStack[parStack.size() - 1];
            parStack.pop_back();
            chars[idx] = '\0';
        }
        
        string result;
        for(char ch : chars) {
            if(ch != '\0') result += ch;
        }
        
        return result;
    }
};