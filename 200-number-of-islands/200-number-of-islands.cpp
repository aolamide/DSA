//DFS Solution
// class Solution {
// public:
//     vector<vector<int>> directions = { {-1,0}, {0,1}, {1,0}, {0,-1}};
    
//     void dfs(vector<vector<char>>& grid, int row, int col) {
//         if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') return;

//         grid[row][col] = '0';
        
//         for(int i = 0; i < directions.size(); i++) {
//             dfs(grid, row + directions[i][0], col + directions[i][1]);
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int count = 0;
//         for(int i = 0; i < grid.size(); i++) {
//             for(int j = 0; j < grid[0].size(); j++) {
//                 if(grid[i][j] == '1') {
//                     count++;
//                     dfs(grid, i, j);
//                 }
//             }
//         }
//         return count;
//     }
// };

//BFS Solution 
class Solution {
public:
    vector<vector<int>> directions = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<vector<int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        
        while(!q.empty()) {
            vector<int> currentPos = q.front();
            q.pop();
            
            for(int i = 0; i < directions.size(); i++) {
                int nextRow = currentPos[0] + directions[i][0];
                int nextCol = currentPos[1] + directions[i][1];
                
                if(nextRow >= 0 && nextRow < grid.size() 
                   && nextCol >= 0 && nextCol < grid[0].size() 
                   && grid[nextRow][nextCol] == '1') {
                    q.push({ nextRow, nextCol });
                    grid[nextRow][nextCol] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};