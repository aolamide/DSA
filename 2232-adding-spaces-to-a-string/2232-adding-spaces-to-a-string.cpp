class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;

        int spacesIdx = 0;

        for(int i = 0; i < s.size(); i++) {
            if(spacesIdx < spaces.size() && i == spaces[spacesIdx]) {
                result += ' ';
                spacesIdx++;
            } 
            result += s[i];
        }

        return result;
    }
};