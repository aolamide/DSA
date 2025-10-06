class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        //sliding window technique
        //keep left pos
        //store chars in map with index

        //keep moving second pointer until you encounter an item with index greater than or equal to left
        //Calculate length, and move left to next char
        unordered_map<char, int> mp;
        int result = 1;
        int left = 0;
        int right = 1;
        mp[s[left]] = 0;

        while(right < s.size()) {
            if(mp.count(s[right]) && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            right++;
            result = max(right - left, result);
        }
        return result;
    }
};