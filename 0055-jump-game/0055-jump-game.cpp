class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(last == 0) return false;
            last = max(nums[i], last - 1);
        }
        
        return true;
    }
};