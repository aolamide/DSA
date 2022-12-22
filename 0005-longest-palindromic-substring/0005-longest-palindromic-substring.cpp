class Solution {
public:
    int palindromeSearch(string s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        int l = 0, r = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int l1 = palindromeSearch(s, i, i);
            int l2 = palindromeSearch(s, i, i + 1);
            
            int size = max(l2, l1);
            
            if(size > r - l + 1) {
                l = i - (size - 1) / 2;
                r = i + size/2;
            }
        }

        return s.substr(l, r - l + 1);
    }
};
