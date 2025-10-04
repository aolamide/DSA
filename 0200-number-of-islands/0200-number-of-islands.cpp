//DFS
// class Solution {
// private:
//     void dfs(int row, int col, vector<vector<char>>& grid) {
//         if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] != '1'){
//             return;
//         }
//         grid[row][col] = '*';
//         dfs(row + 1, col, grid);
//         dfs(row, col + 1, grid);
//         dfs(row - 1, col, grid);
//         dfs(row, col - 1, grid);
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int result = 0;

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == '1') {
//                     dfs(i, j, grid);
//                     result++;
//                 }
//             }
//         }

//         return result;
//     }
// };

//USE BFS
class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({ row, col });

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] != '1'){
                continue;
            }
            grid[row][col] = '*';

            q.push({ row + 1, col });
            q.push({ row, col + 1 });
            q.push({ row - 1, col });
            q.push({ row, col - 1});
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    bfs(i, j, grid);
                    result++;
                }
            }
        }

        return result;
    }
};