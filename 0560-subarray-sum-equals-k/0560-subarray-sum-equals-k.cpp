class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefSum = 0;
        unordered_map<int, int> mp;
        int result = 0;
        
        for(int num : nums) { 
            prefSum += num;
            if(prefSum == k) result++;
            int val = prefSum - k;
            result += mp[val];
            mp[prefSum]++;
        }
        
        return result;
    }
};
//sum(i, j) = sum(0, j) - sum(0, i);
