class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groupMap;

        for(int i = 0; i < strs.size(); i++) {
            vector<int> chars(26, 0);

            for(auto c : strs[i]) chars[c - 'a']++;

            string str(chars.begin(), chars.end());

            if(groupMap.count(str)) {
                groupMap[str].push_back(strs[i]);
            } else {
                vector<string> newArr;
                newArr.push_back(strs[i]);
                groupMap[str] = newArr;
            }

        }

        for(auto group : groupMap) {
            result.push_back(group.second);
        }

        return result;
    }
};