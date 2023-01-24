class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = string(s.size(), 'q');
        for(int i = 0; i < s.size(); i++) {
            result[indices[i]] = s[i];
        }
        return result;
    }
};