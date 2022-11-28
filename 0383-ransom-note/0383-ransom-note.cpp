class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        
        for(char s : magazine) mp[s]++;
        
        for(char s : ransomNote) {
            if(!mp[s]--) {
                return false;
            }
        }
        
        return true;
    }
};