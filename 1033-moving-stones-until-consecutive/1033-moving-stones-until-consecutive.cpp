class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());
        int minMove = 2;
        if(pos[2] - pos[0] == 2) minMove = 0;
        
        else if(pos[1] - pos[0] == 1 || pos[2] - pos[1] == 1 || pos[2] - pos[1] == 2 || pos[1] - pos[0] == 2) minMove = 1;
        
        return { minMove, pos[2] - pos[0] - 2};
    }
};