class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //((nums[i] - nums[j]) * nums[k]) means for every k, the term is maximized by maximizing nums[i] - nums[j], which means maximizing nums[i].
        int maxI = 0;
        int maxDiff = 0;
        long long result = 0;

        for(int k = 0; k < nums.size(); k++) {
            //result
            result = max(result, ((long long)maxDiff * (long long)nums[k]));

            //max (nums[i] - nums[j]) so far
            maxDiff = max(maxDiff, maxI - nums[k]);

            //max nums[i] so far
            maxI = max(maxI, nums[k]);
        }

        return result;
    }
};