class Solution {
public:
    vector<int> parents;
    int find(int x) {
        if(parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }
    
    void uni(int x, int y) {
        int xP = find(x);
        int yP = find(y);
        if(xP == yP) return;
        
        parents[xP] = yP;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parents = vector<int>(n, 0);
        for(int i = 0; i < n; i++) parents[i] = i;
        
        for(auto edge : edges) {
            uni(edge[0], edge[1]);
        }
        
        return find(source) == find(destination);
    }
};