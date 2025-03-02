class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_set<char> usedChars;

        for(int i = 0; i < s.size(); i++) {
            if(!sMap.count(s[i])) {
                if(usedChars.count(t[i])) return false;

                sMap[s[i]] = t[i];
                usedChars.insert(t[i]);
            }

            if(sMap[s[i]] != t[i]) return false;
        }

        return true;
    }
};

//thought process: use a hashmap to map each char in s to t in same positions, if we try to map but another char has been mapped, return false.

//Also, have a hashmap that goes the other way to know which chars have been used to map by another char. or maybe a set to store used chars