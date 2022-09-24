class Solution {
public:
    string st;
    vector<vector<int>> dp;
    int count = 0;
    
    bool isPal(int l, int r) {
        bool valid;
        if(l > r) return true;
        
        if(dp[l][r] > -1) return dp[l][r];
        
        if(l == r) {
            valid = true;
        } else {
            valid = st[l] == st[r] && isPal(l + 1, r - 1);
            isPal(l, r - 1);
            isPal(l + 1, r);
        }
        
        if(valid) {
            count++;
            dp[l][r] = 1;
        } else {
            dp[l][r] = 0;
        }
        
        return valid;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        st = s;
        dp = vector<vector<int>>(n,  vector<int>(n, -1));
        
        isPal(0, n - 1);
        
        return count;
    }
};