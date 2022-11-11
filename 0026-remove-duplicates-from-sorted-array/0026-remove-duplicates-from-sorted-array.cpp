class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int swapPos = 0;
        int lastNum = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != lastNum) {
                nums[swapPos] = nums[i];
                swapPos++;
            }
            lastNum = nums[i];
        }
        
        return swapPos;
    }
};