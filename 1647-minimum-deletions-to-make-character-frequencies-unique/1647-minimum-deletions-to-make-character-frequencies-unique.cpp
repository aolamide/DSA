class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        
        for(char ch : s) {
            mp[ch]++;
        }
        
        priority_queue<int> pq;
        for(auto pair : mp) {
            pq.push(pair.second);
        }
        
        int count = 0;
        while(pq.size() > 1) {
            int top = pq.top();
            pq.pop();
            
            if(pq.top() == top) {
                top -= 1;
                count++;
                if(top > 0) pq.push(top);
            }
        }
        
        return count;
    }
};