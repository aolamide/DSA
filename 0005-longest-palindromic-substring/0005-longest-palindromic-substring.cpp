class Solution {
public:
//     int palindromeSearch(string s, int l, int r) {
//         while(l >= 0 && r < s.size() && s[l] == s[r]) {
//             l--;
//             r++;
//         }
//         return r - l - 1;
//     }
//     string longestPalindrome(string s) {
//         int l = 0, r = 0;
        
//         for(int i = 0; i < s.size(); i++) {
//             int l1 = palindromeSearch(s, i, i);
//             int l2 = palindromeSearch(s, i, i + 1);
            
//             int size = max(l2, l1);
            
//             if(size > r - l + 1) {
//                 l = i - (size - 1) / 2;
//                 r = i + size/2;
//             }
//         }

//         return s.substr(l, r - l + 1);
//     }
    vector<vector<int>> dp;
    int rec(int start, int end, string& s) {
        if(start > end) return true;
        
        if(dp[start][end] > -1) return dp[start][end];
        
        if(start == end) dp[start][end] = 1;
        
        else {
            dp[start][end] = (s[start] == s[end]) && rec(start + 1, end - 1, s);
        }

        return dp[start][end];
        
    }
    string longestPalindrome(string s) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        
        int l = 0, r = 0;
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = s.size() - 1; j >= i; j--) {
                if(rec(i, j, s) == 1) {
                    int size = j - i + 1;
                    
                    if(size > r - l + 1) {
                        l = i;
                        r = j;
                    }
                }
            }
        }
        
        return s.substr(l, r - l + 1);
    }
};
