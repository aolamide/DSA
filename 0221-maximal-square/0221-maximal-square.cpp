class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxL = 0;
    
        vector<int> dp(n + 1, 0);
        int last = 0;
        
        for(int i = m - 1; i >= 0; i--) {
            vector<int> inner(n + 1, 0);
            for(int j = n - 1; j >= 0; j--) {
                int tmp = dp[j];
                if(matrix[i][j] != '0') {
                    dp[j] = 1 + min(min(dp[j], last), dp[j + 1]);
                    maxL = max(maxL, dp[j]);
                } else {
                    dp[j] = 0;
                }
                last = tmp;
            }
            
        }
        
        return maxL * maxL;
    }
};