class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));
        }
        
        
        priority_queue<pair<int, int>> tmp;
        
        for(int i = 0; i < k; i++) {
            tmp.push(make_pair(-1 * pq.top().second, pq.top().first));
            pq.pop();
        }
        
        vector<int> result;
        
        while(!empty(tmp)) {
            result.push_back(tmp.top().second);
            tmp.pop();
        }
        
        return result;
    }
};