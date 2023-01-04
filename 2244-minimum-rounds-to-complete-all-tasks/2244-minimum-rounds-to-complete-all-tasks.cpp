class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int result = 0;
        for(int task : tasks) mp[task]++;
        
        for(auto m : mp) {
            int curr = m.second;
            if(curr < 2) return -1;
            int mod = curr % 3;
            result += curr / 3;
            if(mod > 0) result += 1;
        }
        
        return result;
    }
};