class Solution {
public:
    bool isVowel(char letter) {
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        return vowels.count(letter);
    }
    bool halvesAreAlike(string s) {
        int firstHalf = 0;
        int secondHalf = 0;
        
        for(int i = 0; i < s.size() / 2; i++) {
            if(isVowel(s[i])) firstHalf++;
            if(isVowel(s[i + s.size() / 2])) secondHalf++;
        }
        
        return firstHalf == secondHalf;
    }
};