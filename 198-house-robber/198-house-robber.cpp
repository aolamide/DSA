//recursive solution TLE
// class Solution {
// public:
//     int rec(vector<int>& nums, int i) {
//         if(i < 0) return 0;
//         if(i == 0) return nums[0];
//         if(i == 1) return nums[1];

//         return max(rec(nums, i - 2)  + nums[i], rec(nums, i - 3)  + nums[i]);
//     }
//     int rob(vector<int>& nums) {
//         return max(rec(nums, nums.size() - 1), rec(nums, nums.size() - 2));
//     }
// };

//recursive with DP
class Solution {
public:
    vector<int> dp;
    int rec(vector<int>& nums, int i) {
        if(i < 0) return 0;
        if(i <= 1) return nums[i];
        if(dp[i] > -1) return dp[i];
        
        dp[i] = max(rec(nums, i - 2)  + nums[i], rec(nums, i - 3)  + nums[i]);
        
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n, -1);
        return max(rec(nums, n - 1), rec(nums, n - 2));
    }
};