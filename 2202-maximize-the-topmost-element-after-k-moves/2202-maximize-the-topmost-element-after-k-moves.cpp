class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxIdx = 0;
        if(k == 0) return nums[0];
        
        if(nums.size() == 1) {
            if(k == 1) return -1;
            if(k % 2 == 0) return nums[0];
            return -1;
        }
        
        if(k == 1) return nums[1] ;
        
        for(int i = 1; i < nums.size(); i++) {
            if(i == k - 1) {
                return max(nums[maxIdx], nums[k]);
            }
            if(nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }
        
        return nums[maxIdx];
    }
};