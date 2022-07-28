class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charMap;
        for(auto str : s) charMap[str]++;
        
        for(auto str : t) {
            if(charMap[str] == 0) return false;
            if(charMap[str] == 1) charMap.erase(str);
            else charMap[str]--;
        }
        
        if(charMap.size() == 0) return true;
        return false;
    }
};