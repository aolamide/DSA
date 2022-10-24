class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int result = 0;
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (matrix[i][j] - '0') + min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]);
                    result = max(result, dp[i][j]);
                }
                
            }
        }
//                 vector<int> dp(n + 1, 0);
//         for(int i = m - 1; i >= 0; i--) {
//             for(int j = n - 1; j >= 0; j--) {
//                 if(matrix[i][j] == '0') {
//                     dp[j] = 0;
//                 } else {
//                     dp[j] = (matrix[i][j] - '0') + min(min(dp[j], dp[i]), dp[j + 1]);
//                     result = max(result, dp[j]);
//                 }
                
//             }
//         }
        
        
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        
        return result * result;
    }
};