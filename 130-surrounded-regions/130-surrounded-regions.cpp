class Solution {
public:
    int count = 0;
    void dfs(vector<vector<char>>& board, int row, int col) {
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O') return;
        board[row][col] = 'N';
        
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }
        
        for(int i = 0; i < cols; i++) {
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[rows - 1][i] == 'O') dfs(board, rows - 1, i);
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'N') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};