class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqs;
        
        for(auto val : arr) freqs[val]++;
        
        
        //could also use quick sort to sort frequencies
        priority_queue<int> pq;
        
        for(auto freq : freqs) pq.push(freq.second);
        
        int count = 0;
        
        int sum = 0;
        
        while(sum < arr.size() / 2) {
            sum += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};