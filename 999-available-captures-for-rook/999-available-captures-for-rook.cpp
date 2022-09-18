class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        pair<int, int> rookPos;
        
         for(int i = 0; i < 8; i++) {
             for(int j = 0; j < 8; j++) {
                 if(board[i][j] == 'R') {
                     rookPos = make_pair(i, j);
                     break;
                 }
             }
         }    
        int count = 0;
        for(int j = 0; j < 8; j++) {
            char curr = board[rookPos.first][j];
            if(curr != '.') {
                if(j < rookPos.second) {
                    if(curr == 'p') count = 1;
                    if(curr == 'B') count = 0;
                } else if(j > rookPos.second) {
                    if(curr == 'p') count++;
                    break;
                }
            }

        }
        
        int cnt = 0;
        for(int i = 0; i < 8; i++) {
            char curr = board[i][rookPos.second];
            if(curr != '.') {
                if(i < rookPos.first) {
                    if(curr == 'p') cnt = 1;
                    if(curr == 'B') cnt = 0;
                } else if(i > rookPos.first) {
                    if(curr == 'p') count++;
                    break;
                }
            }

        }
        count += cnt;
        
        return count;
    }
};