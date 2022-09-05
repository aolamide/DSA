//approach: 
//go to borders of pacific ocean, and mark every cell that can get to the border through dfs.
//in a similar way, dfs on every border of atlantic ocean, and push into result every cell that had been marked for pacific.
//all cells are processed only once in both atlantic and pacific checks.

class Solution {
public:
    vector<vector<int>> directions = { {-1,0}, {0,1}, {1,0}, {0,-1}};
    int m;
    int n;
    vector<vector<int>> seen;
    vector<vector<int>> result;
    bool secondCheck = false;
    
    void dfs(vector<vector<int>>& heights, int x , int y, int lastCell) {
        if(x < 0 || x >= m || y < 0 || y >= n || heights[x][y] < lastCell) return;
        
        int seenVal = seen[x][y];
        if(seenVal == 2) return;
        
        
        if(seenVal) {
            if(seenVal == 2)  {
                return;
            }
            if(!secondCheck && seenVal == 1) return;
            result.push_back({x,y});
        }
        
        if(!secondCheck) seen[x][y] = 1;
        else seen[x][y] = 2;
        
        for(int i = 0; i < 4; i++) {
            dfs(heights, x + directions[i][0], y + directions[i][1], heights[x][y]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        seen = vector<vector<int>>(m, vector<int>(n));
        
        //PACIFIC
        //west
        for(int i = 0; i < m; i++) {
            dfs(heights, i, 0, -1);
        }
        
        //north
        for(int j = 0; j < n; j++) {
            dfs(heights, 0, j, -1);
        }
        
        secondCheck = true;
        
        //ATLANTIC
        //east
        for(int i = 0; i < m; i++) {
            dfs(heights, i, n - 1, -1);
        }
        
        //south
        for(int j = 0; j < n; j++) {
            dfs(heights, m - 1, j, -1);
        }
        
        return result;
    }
};