class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> dir = {0, 1};
        vector<vector<int>> result(n, vector<int>(n, 0));
        int r = 0;
        int c = 0;
        int num = 1;
        
        while(num <= n * n) {
            result[r][c] = num;
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            
            if(nextR < 0 || nextR == n || nextC < 0 || nextC == n || result[nextR][nextC]) {
                int diff = dir[1] - dir[0];
                if(dir[0] == 0) {
                    //go down or up
                    dir[0] += diff;
                    dir[1] = 0;
                } else {
                    //go left or right
                    dir[1] += diff;
                    dir[0] = 0;
                }
                nextR = r + dir[0];
                nextC = c + dir[1];
            }
            r = nextR;
            c = nextC;
            num++;
        }
        
        return result;
    }
};