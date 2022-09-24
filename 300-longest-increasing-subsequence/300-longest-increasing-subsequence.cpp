class Solution {
public:
    int recurse(vector<int>& nums, vector<vector<int>>& dp, int currIndex, int valIndex) {
        if(currIndex < 0) return 0;
        
        if(dp[currIndex][valIndex] > -1) return dp[currIndex][valIndex];
        
        int recurseSameValue = recurse(nums, dp, currIndex - 1, valIndex);
        
        if(nums[currIndex] >= nums[valIndex]) {
            dp[currIndex][valIndex] = recurseSameValue;
        } else {
            dp[currIndex][valIndex] = max(1 + recurse(nums, dp, currIndex - 1, currIndex), recurseSameValue);
        }
        
        return dp[currIndex][valIndex];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            result = max(result, 1 + recurse(nums, dp, i - 1, i));
        }
        
        return result;
    }
};