class Solution {
public:
    int scan(int i, string& s, vector<int>& dp) {
        if(s[i] == '0') return 0;

        if(i >= s.size() - 1) return 1;

        if(dp[i] > -1) return dp[i];

        if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
            dp[i] = scan(i + 1, s, dp) + scan(i + 2, s, dp);
        } else {
            dp[i] = scan(i + 1, s, dp);
        }

        return dp[i];

    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return scan(0, s, dp);
    }
};