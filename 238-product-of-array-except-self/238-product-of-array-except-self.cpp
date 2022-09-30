class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        
        int prefix = 1;
        
        for(int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        prefix = 1;
        
        for(int i = n - 1; i >= 0; i--) {
            result[i] *= prefix;
            prefix *= nums[i];
        }
        
        
        return result;
    }
};