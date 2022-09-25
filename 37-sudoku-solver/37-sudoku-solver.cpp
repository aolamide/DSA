class Solution {
public:
    vector<unordered_set<char>> rows = vector<unordered_set<char>>(9);
    vector<unordered_set<char>> cols = vector<unordered_set<char>>(9);
    vector<unordered_set<char>> boxes = vector<unordered_set<char>>(9);
    
    bool isValid(int row, int col, char val) {
        return !rows[row].count(val) && !cols[col].count(val) && !boxes[getBoxId(row,col)].count(val);
    }
    
    int getBoxId(int row, int col) {
        return 3 * (row/3) + (col/3);
    }
    
    vector<int> getNextPos(int x, int y) {
        if(x == 8 && y == 8) return { -1, -1 };
        if(y < 8) {
            return { x, y + 1 };
        }
        return { x + 1 , 0 };
    }
    
    bool recurse(int row, int col, vector<vector<char>>& board) {
        if(row < 0) return true;
        vector<int> nextPos = getNextPos(row, col);
        
        if(board[row][col] != '.') {
            return recurse(nextPos[0], nextPos[1], board);
        } else {
            for(char i = '1'; i <= '9'; i++) {
                
                board[row][col] = i;
                
                if(isValid(row, col, i)) {
                    rows[row].insert(i);
                    cols[col].insert(i);
                    boxes[getBoxId(row,col)].insert(i);

                    if(recurse(nextPos[0], nextPos[1], board)) {
                        return true;
                    };
                    
                    rows[row].erase(i);
                    cols[col].erase(i);
                    boxes[getBoxId(row,col)].erase(i); 
                }
                board[row][col] = '.';
            }
        }
        
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[getBoxId(i,j)].insert(board[i][j]);
                }
            }
        }
        
        recurse(0, 0, board);  
    }
};