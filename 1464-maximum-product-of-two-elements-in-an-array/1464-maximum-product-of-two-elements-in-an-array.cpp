class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
        
//         return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
        priority_queue<int> pq;
        int a, b;
        
        for(int i=0;i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        a = pq.top() - 1;
        pq.pop();
        b = pq.top() - 1;
        
        return a * b;
    }
};