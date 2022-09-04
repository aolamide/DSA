class Solution {
private:
    vector<int> boxBoundary;
    unordered_map<int, unordered_set<char>> rowsMap;
    unordered_map<int, unordered_set<char>> colsMap;
public:
    bool dfs(vector<vector<char>>& board, int row, int col, unordered_set<char>& seen) {
        if(row >= board.size() || col >= board[0].size() || row > boxBoundary[0] || col > boxBoundary[1]) return true;
                
        char curr = board[row][col];
        
        if(curr != '.') {
            board[row][col] = '.';
            
            if(seen.count(curr)) return false;
            seen.insert(curr);
            
            if(rowsMap[row].count(curr) || colsMap[col].count(curr)) return false;

            rowsMap[row].insert(curr);
            colsMap[col].insert(curr);
        }
        
        return dfs(board, row, col + 1, seen) && dfs(board, row + 1, col, seen);
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i <= 8; i += 3) {
            for(int j = 0; j <= 8; j+=3) {
                unordered_set<char> seen;
                boxBoundary = {i + 2, j + 2};
                if(!dfs(board, i, j, seen)) return false;
            }
        }
        
        return true;
    }
};