class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> dir = {0, 1};
        vector<int> result;
        int r = 0;
        int c = 0;
        
        int t = -1, b = matrix.size(), l = -1, R = matrix[0].size();
        
        while(r > t && r < b && c > l && c < R) {
            result.push_back(matrix[r][c]);
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            
            if(nextR == t || nextR == b || nextC == l || nextC == R) {
                int diff = dir[1] - dir[0];
                if(dir[0] == 0) {
                    //go down or up
                    if(dir[1] == 1) {
                        t++;
                    } else {
                        b--;
                    }
                    dir[0] += diff;
                    dir[1] = 0;
                } else {
                    if(dir[0] == 1) {
                        R--;
                    } else {
                        l++;
                    }
                    dir[1] += diff;
                    dir[0] = 0;
                }
                nextR = r + dir[0];
                nextC = c + dir[1];
            }
            r = nextR;
            c = nextC;
        }
        
        return result;
    }
};