class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char, int> charMap;
        int n = s.size();
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(charMap.count(s[i]) && charMap[s[i]] >= l) {
                result = max(result, i - l);
                l = charMap[s[i]] + 1;
            }
            charMap[s[i]] = i;
        }
        
        result = max(result, n - l);
        return result;
    }
};