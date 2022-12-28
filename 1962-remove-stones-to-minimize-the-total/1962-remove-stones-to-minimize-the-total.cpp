class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        
        for(int pile : piles) pq.push(pile);
        
        while(k-- > 0) {
            int curr = pq.top();
            pq.pop();
            pq.push(curr - curr/2);
        }
        
        int result = 0;
        
        while(!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
        
        return result;
    }
};