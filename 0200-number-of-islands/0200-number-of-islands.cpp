class Solution {
public:
    
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '#';
        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
    }
        
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            
            for(int j = 0; j < grid[0].size(); j++) {
                 if(grid[i][j] == '1') {
                     result++;
                     dfs(i, j, grid);
                 }
                
            }
        }
        
        return result;
    }
};