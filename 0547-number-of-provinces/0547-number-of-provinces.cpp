class Solution {
public:
    vector<int> parents;
    vector<int> rank;
    int find(int x) {
        if(parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    };
    
    void unionF(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(rank[px] > rank[py]) {
            parents[py] = px;
        } else if(rank[px] < rank[py]) {
            parents[px] = py;
        } else {
            parents[py] = px;
            rank[py]++;
        }
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parents = vector<int>(n);
        rank = vector<int>(n, 1);
        iota(parents.begin(), parents.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    if(isConnected[i][j] == 1) unionF(i, j);
                }
            }
        }
        
        unordered_set<int> provinces;
        
        for(int i = 0; i < n; i++) {
            provinces.insert(find(i));
        }
        
        return provinces.size();
    }
};