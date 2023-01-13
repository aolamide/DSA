class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || c == grid[0].size() || r == grid.size() || grid[r][c] == 0) {
            return 0;
        }
        
        int tmp = grid[r][c];
        grid[r][c] = 0;
        int curr = max({ dfs(r + 1, c, grid), dfs(r, c + 1, grid), dfs(r - 1, c, grid), dfs(r, c - 1, grid) });
        grid[r][c] = tmp;
        return grid[r][c] + curr;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0) result = max(result, dfs(i, j, grid));
            }
        }
        
        return result;
    }
};