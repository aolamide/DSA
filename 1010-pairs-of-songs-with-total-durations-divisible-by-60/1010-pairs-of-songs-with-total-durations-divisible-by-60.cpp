class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int count = 0;
        
        for(auto t : time) {
            int mod = t % 60;
            count += mod ? mp[60 - mod] : mp[mod];
            
            mp[mod]++;
        }
        
        return count;
    }
};