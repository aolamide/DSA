class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) 
                    q.push({i, j});
            }
        }
        if (q.empty() || q.size() == n * n) return -1;
        int distance = -1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int i = x + dir.first, j = y + dir.second;
                    if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0) {
                        grid[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};