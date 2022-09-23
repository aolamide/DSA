class Solution {
private:
    int size;
    int allowedMoves;
    int count;
    vector<vector<vector<double>>> dp;
    vector<vector<int>> dirs = {{1,2}, {-1,2}, {1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    
    double getCellProb(int r, int c, int moves) {
        if(r >= size || c >= size || c < 0 || r < 0) {
            return 0;
        }
        if(moves == 0) return 1;
        
        if(dp[moves][r][c]) return dp[moves][r][c]; 
        
        double prob;
        
        for(vector<int> dir : dirs) {
            prob += getCellProb(r + dir[0], c + dir[1], moves - 1);
        }
        
        prob /= 8;
        
        dp[moves][r][c] = prob;
        
        return prob;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        if(k == 0) return 1;
        size = n;
        allowedMoves = k;
        dp = vector<vector<vector<double>>>(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        
        return getCellProb(row, column, k);
    }
};