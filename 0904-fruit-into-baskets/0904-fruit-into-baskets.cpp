class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int result = 1;
        int l = 0;
        int r = 0;
        
        while(r < fruits.size()) {
            mp[fruits[r]]++;
            
            if(mp.size() <= 2) {
                result = max(result, r - l + 1);
            } else {
                if (--mp[fruits[l++]] == 0) mp.erase(fruits[l - 1]);
            }
            
            r++;
            
            // for(auto k : mp) {
            //     cout << k.first << " : " << k.second << ",";
            // }
            // cout << endl;
        }
        
        return result;
        
    }
};