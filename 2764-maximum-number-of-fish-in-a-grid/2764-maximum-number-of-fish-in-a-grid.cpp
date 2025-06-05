class Solution {
    int dfs(vector<vector<int>>& grid, int i , int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) return 0 ;
        int res = 0;
        res += grid[i][j];
        grid[i][j] = -1;

        res += dfs(grid, i - 1, j);
        res += dfs(grid, i + 1, j);
        res += dfs(grid, i, j + 1);
        res += dfs(grid, i, j - 1);

        return res;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0 ;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] > 0) {
                    res = max(res,dfs(grid,i,j)) ;
                }
            }
        }
        return res ;
    }   
};