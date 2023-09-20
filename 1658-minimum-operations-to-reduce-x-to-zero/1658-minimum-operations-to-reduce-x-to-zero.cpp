class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto num : nums) sum += num;
        // cout << sum;
        int target = sum - x;
        if(target == 0) return nums.size();
        if(target < 0) return -1;
        
        int l = 0, r = 0, curr = nums[0], ans = -1;
        
        while(r < nums.size()) {
            if(curr < target) {
                r++;
                if(r == nums.size()) break;
                curr += nums[r];
            } else if(curr > target) {
                curr -= nums[l];
                l++;
            } else if(curr == target) {
                ans = max(ans, r - l + 1);
                curr -= nums[l];
                l++;
            }

        }
        
        if(ans == -1) return ans;
        return nums.size() - ans;
    }
};