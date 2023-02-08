class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> mp = {{"type", 0}, {"color", 1}, {"name",  2}};
        int result = 0;
        for(auto item : items) {
            if(item[mp[ruleKey]] == ruleValue) result++;
        }
        return result;
    }
};