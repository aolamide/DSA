class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if(nums.size() == 1) return true;
        
        for(int i = 1; i < dp.size(); i++) {
            if(dp[i - 1] == 0) return false;
            dp[i] = max(nums[i], dp[i - 1] - 1);
        }
        
        return true;
    }
};