class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] != '1'){
            return;
        }
        grid[row][col] = '*';
        dfs(row + 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row - 1, col, grid);
        dfs(row, col - 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    result++;
                }
            }
        }

        return result;
    }
};