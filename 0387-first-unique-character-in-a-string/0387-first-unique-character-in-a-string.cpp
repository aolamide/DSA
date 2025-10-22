class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, pair<int, int>> mp;

        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i])) {
                mp[s[i]].first++;
            } else {
                mp[s[i]] = {1, i};
            }
        }
        int result = INT_MAX;
        for(auto m: mp) {
            if(m.second.first == 1) {
                result = min(result, m.second.second);
            }
        }

        return result == INT_MAX ? -1: result;
    }
};