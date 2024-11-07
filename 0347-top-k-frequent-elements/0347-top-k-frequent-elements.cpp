class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> result;
        
        for(int num : nums) mp[num]++;
        
        vector<vector<int>> t(nums.size() + 1);
        
        for(auto m : mp) {
            t[m.second].push_back(m.first);
        }
        for(int i = t.size() - 1; i >= 0 && result.size() < k; i--) {
            for(int a : t[i]) {
                result.push_back(a);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};