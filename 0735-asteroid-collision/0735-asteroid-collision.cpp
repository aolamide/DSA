class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {       
        stack<int> s;
        
        for(int curr : asteroids) {
            while(true) {
                if(curr > 0 || s.empty() || s.top() < 0) {
                    s.push(curr);
                    break;
                } 
                int top = s.top();

                if(top == abs(curr)) {
                    s.pop();
                } else if(top < abs(curr)) {
                    s.pop();
                    s.push(curr);
                }

                if(!s.empty()) {
                    curr = s.top();
                    s.pop(); 
                } else {
                    break;
                }

            }
                
        }
        
        int n = s.size();
        
        vector<int> result(n);
        
        while(!s.empty()) {
            result[n - 1] = s.top();
            s.pop();
            n--;
        }
        
        return result;
    }
};
