class Solution {
public:
    int minCost(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return INT_MAX;
        
        if(dp[row][col] > -1) return dp[row][col];
        
        dp[row][col] = grid[row][col] + min( minCost(grid, row - 1, col, dp), minCost(grid, row, col - 1, dp) );
        
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return minCost(grid, m - 1, n - 1, dp);
    }
};