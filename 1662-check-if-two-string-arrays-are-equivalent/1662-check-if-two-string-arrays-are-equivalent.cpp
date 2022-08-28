class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int ptr1 = 0;
        int ptr2 = 0;
        
        int c1 = 0;
        int c2 = 0;
        while(ptr1 < word1.size() && ptr2 < word2.size()) {
            
            if(word1[ptr1][c1] != word2[ptr2][c2]) return false;
            
            if(++c1 >= word1[ptr1].size()) {
                c1 = 0;
                ptr1++;
            }
            
            if(++c2 >= word2[ptr2].size()) {
                c2 = 0;
                ptr2++;
            }
            
        }
        
        if(ptr1 == word1.size() && ptr2 == word2.size()) return true;
        
        return false;
    }
};