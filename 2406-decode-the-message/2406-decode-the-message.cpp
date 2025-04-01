class Solution {
public:
    string decodeMessage(string key, string message) {
        //map for mapping keys to chars.
        //Initially map space to itself.
        unordered_map<char, char> chMap = { {' ', ' '} };

        //start from 0. 0 -> 'a', 1 -> 'b', and so on.
        int currAlphabet = 0;

        //map keys to chars
        for(char ch : key) {
            if(!chMap.count(ch)) {
                chMap[ch] = 'a' + currAlphabet++;
            }
        }

        //build decoded message
        string decoded;
        for(char ch : message) {
            decoded += chMap[ch];
        }

        return decoded;
    }
};