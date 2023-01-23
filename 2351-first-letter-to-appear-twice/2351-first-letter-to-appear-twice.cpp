class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> ss;
        for(char ch : s) {
            if(ss.count(ch)) return ch;
            ss.insert(ch);
        }
        return '#';
    }
};