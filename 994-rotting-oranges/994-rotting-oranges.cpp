class Solution {
private:
    vector<vector<int>> directions = { {-1, 0 }, {0, 1}, {1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<vector<int>> rq;
        int freshCount = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) rq.push({ i, j });
                if(grid[i][j] == 1) freshCount++;
            }
        }
        
        int round = rq.size();
        
        while(!rq.empty()) {
            if(round == 0) {
                time++;
                round = rq.size();
            }
            
            round--;
            vector<int> currentPos = rq.front();
            rq.pop();
            
            for(int i = 0; i <= 3; i++) {
                int nextRow = currentPos[0] + directions[i][0];
                int nextCol = currentPos[1] + directions[i][1];

                if(nextRow >= 0 && nextRow < grid.size() 
                   && nextCol >= 0 && nextCol < grid[0].size() 
                   && grid[nextRow][nextCol] == 1) {
                    rq.push({ nextRow, nextCol });
                    grid[nextRow][nextCol] = 2;
                    freshCount--;
                }
            }          
        }
        
        
        if(freshCount) return -1;

        return time;  
    }
};