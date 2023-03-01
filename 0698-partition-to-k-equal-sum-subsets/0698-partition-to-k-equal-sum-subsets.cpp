class Solution {
public:
    bool backtrack(vector<int>& nums, vector<int>& subsetSums, int index, int target) {
        if (index == nums.size()) {
            return true;
        }
        for (int i = 0; i < subsetSums.size(); i++) {
            if (subsetSums[i] + nums[index] <= target) {
                subsetSums[i] += nums[index];
                if (backtrack(nums, subsetSums, index+1, target)) {
                    return true;
                }
                subsetSums[i] -= nums[index];
            }
            if (subsetSums[i] == 0) {
                break; 
            }
        }
        return false;
    }
   bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> subsetSums(k, 0);
        return backtrack(nums, subsetSums, 0, target);
    }
};

//[2,2,2,2,3,4,5]
//4