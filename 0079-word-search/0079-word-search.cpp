class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool backtrack(vector<vector<char>>& board, int row, int col, string& word, int wordIdx) {
        if(wordIdx == word.size()) {
            return true;
        }
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[wordIdx] || board[row][col] == '*') {
            return false;
        }
        
        char original = board[row][col];
        
        board[row][col] = '*';
        
        for(int i = 0; i < 4; i++) {
            int nextRow = row + dirs[i][0];
            int nextCol = col + dirs[i][1];
            
            if(backtrack(board, nextRow, nextCol, word, wordIdx + 1)) {
                return true;
            }
        }
        board[row][col] = original;
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(backtrack(board, i, j, word, 0)) return true;
                }
            }
        }
        
        return false;
    }
};