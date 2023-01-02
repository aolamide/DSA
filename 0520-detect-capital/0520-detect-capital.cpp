class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upCase = isupper(word[1]);
        if(upCase && !isupper(word[0])) return false;
        
        for(int i = 2; i < word.size(); i++) {
            bool currUpper = isupper(word[i]);
            if((currUpper && !upCase) || (!currUpper && upCase)) return false;
        }
        
        return true;
    }
};