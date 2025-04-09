class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for(int gift : gifts) {
            sum += gift;
            pq.push(gift);
        } 

        while(!pq.empty() && k--) {
            int num = pq.top();
            pq.pop();
            int sRoot = sqrt(num);

            sum -= (num - sRoot);
            pq.push(sRoot);
        }

        return sum;
    }
};