class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int num : arr) mp[num]++;
        
        unordered_set<int> freqs;
        for(auto val : mp) {
            if(freqs.count(val.second)) return false;
            freqs.insert(val.second);
        }
        
        return true;
    }
};