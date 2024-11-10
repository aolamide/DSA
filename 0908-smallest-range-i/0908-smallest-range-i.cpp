class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        //maximise min number
        //minimize max number
        
        //adding k
        int mn = nums[0];
        int mx = nums[0];
        
        for(int i = 0;  i < nums.size(); i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        
        //add k to min, and subtract k from min
        int bestMin = (mn + k);
        int bestMax = (mx - k);
        
        //if bestMin is more or equal to bestMax, then we can make all numbers equal and score = 0
        if(bestMin >= bestMax) return 0;
        
        return bestMax - bestMin;
    }
};