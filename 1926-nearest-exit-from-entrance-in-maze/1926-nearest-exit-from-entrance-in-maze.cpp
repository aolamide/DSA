class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0 ,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<vector<int>, int>> q;
        vector<vector<int>> seen(maze.size(), vector<int>(maze[0].size(), 0));
        
        q.push({entrance, 0});
        
        int result = INT_MAX;
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first[0];
            int c = curr.first[1];
            if(seen[r][c]) continue;
            seen[r][c] = 1;
            int steps = curr.second;
            // cout << r << " " << c << " " << " " << steps << endl;
            //if at border, check steps
            if((r == 0 || c == 0 || r == maze.size() - 1 || c == maze[0].size() - 1) && !(r == entrance[0] && c == entrance[1])) {
                result = min(result, steps);
            }
            // cout << result << endl;
            
            for(auto dir : dirs) {
                int nextR = r + dir[0];
                int nextC = c + dir[1];
                if(nextR >= 0 && nextC >= 0 && nextR < maze.size() && nextC < maze[0].size() && maze[nextR][nextC] == '.' && !seen[nextR][nextC]) {
                    q.push({{nextR, nextC}, steps + 1});
                }
            }
            
        }
        
        if(result == INT_MAX) return -1;
        
        return result;
    };
};