class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum = 0;
        for(int num : nums) sum += num;
        
        long currSum = 0;
        long result = sum / nums.size();
        int ans = nums.size() - 1;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            currSum += nums[i];
            long diff = abs(long(currSum / (i + 1) - (sum - currSum)/(nums.size() - i - 1)));
            if(diff < result || (diff == result && i < ans)) {
                ans = i;
                result = diff;
            }
        }
        
        return ans;
    }
};