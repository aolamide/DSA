class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        if(!s.size()) return true;
        
        int p1 = 0;
        int p2 = 0;
        
        while(p2 < t.size()) {
            
            if(s[p1] == t[p2]) {
                p1++;
                p2++;
                if(p1 == s.size()) return true;
            } else {
                p2++;
            }
            
        }
        
        return false;
    }
};