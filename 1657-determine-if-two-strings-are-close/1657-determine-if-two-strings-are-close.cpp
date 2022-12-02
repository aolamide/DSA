class Solution {
public:
    bool closeStrings(string word1, string word2) {
        sort(word2.begin(), word2.end());
        sort(word1.begin(), word1.end());
        
        vector<int> charsWord1(26, 0);
        vector<int> charsWord2(26, 0);
        
        for(char s : word1) charsWord1[s - 'a']++;
        for(char s : word2) charsWord2[s - 'a']++;
        
        for(int i = 0; i < 26; i++) {
            if((charsWord1[i] && !charsWord2[i]) || (charsWord2[i] && !charsWord1[i])) return false;
        }
        
        sort(charsWord1.begin(), charsWord1.end(), greater<int>());
        sort(charsWord2.begin(), charsWord2.end(), greater<int>());
        
        for(int i = 0; i < 26; i++) {
            if(charsWord1[i] != charsWord2[i]) return false;
            if(charsWord1[i] == 0 && charsWord2[i] == 0) break;
        }
        
        return true;
    }
};