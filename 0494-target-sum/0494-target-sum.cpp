class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        
        return count;
    }
    
    void backtrack(vector<int>& nums, int target, int idx, int sum) {
        if(idx == nums.size()) {
            if(sum == target){
              count++;   
            }
            return;
        }
        
        backtrack(nums, target, idx + 1, sum - nums[idx]);
        backtrack(nums, target, idx + 1, sum + nums[idx]);
    }
};