class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increases = 1;
        int decreases = 1;
        
        int result = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            increases = nums[i - 1] < nums[i] ? ++increases : 1;
            decreases = nums[i - 1] > nums[i] ? ++decreases : 1;
            
            result = max({ result, increases, decreases });
        }
        
        return result;
    }
};