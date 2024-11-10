class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i = 0; i < s2.size(); i++) {
            if(s1[i] != s2[i]) diff++;
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for(auto mp : mp1) {
            if(mp2[mp.first] != mp.second) return false;
        }
        return diff == 2 || diff == 0;
    }
};