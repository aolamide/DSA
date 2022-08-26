class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        if(n < 6);
        unordered_set<char> reds;
        unordered_set<char> blues;
        unordered_set<char> greens;
        
        for(int i = 0; i < n; i += 2) {
            if(rings[i] == 'R') {
                reds.insert(rings[i + 1]);
            }
            else if(rings[i] == 'G') {
                greens.insert(rings[i + 1]);
            } else blues.insert(rings[i + 1]);
        }
        
        int count = 0;
        
        for(auto pos : reds) {
            if(greens.count(pos) && blues.count(pos)) count++;
        }
        
        return count;
    }
};