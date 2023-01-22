class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(!mp.count(ch)) {
                mp[ch] = {1, i};
            } else {
                mp[ch].first++;
            }
        }
        int result = INT_MAX;
        for(auto m : mp) {
            if(m.second.first == 1) {
                result = min(result, m.second.second);
            }
        }
        
        if(result < INT_MAX) return result;
        return -1;
    }
};