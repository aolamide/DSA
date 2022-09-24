class Solution {
public:
    int count = 0;
    
    int isPal(string& st, int l, int r, vector<vector<int>>& dp) {
        if(l >= r) return 1;
        
        if(dp[l][r] > -1) return dp[l][r];
        
        dp[l][r] = st[l] == st[r] ? isPal(st, l + 1, r - 1, dp) : 0;
        isPal(st, l, r - 1, dp);
        isPal(st, l + 1, r, dp);
        
        count += dp[l][r];
        
        return dp[l][r];
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp = vector<vector<int>>(n,  vector<int>(n, -1));
        
        isPal(s, 0, n - 1, dp);
        
        return count + n;
    }
};

