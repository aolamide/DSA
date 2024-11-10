class Solution {
public:
    int enclaves = 0;
    void dfs(int row, int col, vector<vector<int>>& grid) {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0) {
            return;
        }        
        grid[row][col] = 0;

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
               //do dfs from boundaries only
                if(i * j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) dfs(i, j, grid);
            }
        }
        
        //count how many ones are left
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                result += grid[i][j];
            }
        }
        
        return result;
    }   
};