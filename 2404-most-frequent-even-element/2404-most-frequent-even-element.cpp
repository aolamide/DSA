class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int result = INT_MAX;
        int maxFreq = INT_MIN;
        unordered_map<int, int> mp;
        for(int num : nums) {
            if(num % 2 == 0) {
                mp[num]++;
                if(mp[num] > maxFreq) {
                    maxFreq = mp[num];
                    result = num;
                } else if(mp[num] == maxFreq) {
                    result = min(num, result);
                }
            }
        }
        
        if(result == INT_MAX) return -1;
        return result;
    }
};