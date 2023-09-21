class Solution {
private:
    bool valid = false;
    unordered_map<int, vector<unordered_set<int>>> numMap = { 
        {1, {{}, {1,3,5}, {}, {1,4,6}}},
        {2, {{2,3,4}, {}, {2,5,6}, {}}},
        {3, {{}, {}, {2,5,6}, {1,4,6}}},
        {4, {{}, {1,3,5}, {2,5,6}, {}}},
        {5, {{2,3,4}, {}, {}, {1,4,6}}},
        {6, {{2,3,4}, {1,3,5}, {}, {}}},
    };
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    void dfs(vector<vector<int>>& grid, int r, int c) {
        if(r == grid.size() -1 &&  c == grid[0].size() - 1) {
            valid = true;
            return;
        }
        
        int curr = grid[r][c];
        grid[r][c] *= -1;
        for(int i = 0; i < dirs.size(); i++) {
            int nextRow = r + dirs[i][0];
            int nextCol = c + dirs[i][1];
            if(nextRow < 0 || nextRow == grid.size() || nextCol < 0 || nextCol == grid[0].size() || grid[nextRow][nextCol] < 0) {
                continue;
            }
            
            if(!numMap[curr][i].count(grid[nextRow][nextCol])) continue;
            
            dfs(grid, nextRow, nextCol);
        }
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        //1 -> [] [1, 3, 5] [] [1, 4, 6]
        //2 -> [2,3, 4] [] [2, 5, 6] []
        //3 -> [] [] [2, 5, 6] [1, 4, 6]
        //4 -> [] [1, 3, 5] [2, 5, 6] []
        //5 -> [2, 3, 4] [] [] [1, 4, 6]
        //6 -> [2, 3, 4] [1, 3, 5] [] []
        
        // {-1, 0} {0, 1} {1, 0} {0, -1}
        dfs(grid, 0, 0);
        return valid;
    }
};