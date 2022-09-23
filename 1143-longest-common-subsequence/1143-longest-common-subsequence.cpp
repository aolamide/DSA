class Solution {
public:
    string s1;
    string s2;
    vector<vector<int>> dp;
    
    int solve(int i, int j) {
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(dp[i][j] > -1) return dp[i][j];
        
        dp[i][j] = s1[i] == s2[j] ? 1 + solve(i + 1, j + 1) : max(solve(i + 1, j), solve(i, j + 1));

        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        dp = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
        
        return solve(0, 0);
    }
};