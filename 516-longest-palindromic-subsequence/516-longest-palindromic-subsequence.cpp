class Solution {
public:
    vector<vector<int>> dp;
    string st;
    int solve(int i, int j) {
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] > -1) return dp[i][j];
        
        dp[i][j] = st[i] == st[j] ? 2 + solve(i + 1, j - 1) : max(solve(i + 1, j), solve(i, j - 1));

        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        st = s;
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        return solve(0, n - 1);
    }
};