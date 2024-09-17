class Solution {
public:
    int landAreaPerimeter(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0){
            return 1;
        }
        return 0;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) continue;
                //top [i - 1][j]
                perimeter += landAreaPerimeter(grid, i - 1, j);
                //down [i + 1][j]
                perimeter += landAreaPerimeter(grid, i + 1, j);
                //left [i][j - 1]
                perimeter += landAreaPerimeter(grid, i, j - 1);
                //right [i][j + 1]
                perimeter += landAreaPerimeter(grid, i, j + 1);
            }
        }
        
        return perimeter;
    }
};