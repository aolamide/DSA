class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pref(nums.size());
        pref[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        
        int result = nums[0];
        int low = 0;
        for(int i = 0; i < pref.size(); i++) {
            
            result = max(pref[i] - low, result);
            low = min(low, pref[i]);
        }
        
        return result;
    }
};