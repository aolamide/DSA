class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;
        
        for(int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            mp[size].push_back(i);
            if(mp[size].size() == size){
                result.push_back(mp[size]);
                mp[size] = {};
            }
        }
        
        return result;
    }
};