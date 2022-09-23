class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int low = 0;
        int result = nums[0];
        int lastSum = 0;
        
        for(int i = 0; i < nums.size(); i++)  {
            lastSum += nums[i];
            result = max(lastSum - low, result);
            low = min(lastSum, low);  
        }
        
        return result;
    }
};