class DisjointSet {
    private:
        vector<int> parents;
        vector<int> ranks;
    public:
        DisjointSet(int n) {
            parents = vector<int>(n + 1);
            iota(parents.begin(), parents.end(), 0);
            ranks = vector<int>(n + 1, 1);
        }
        int find(int x) {
            if(x == parents[x]) return x;
            return parents[x] = find(parents[x]);
        }
    
        void uni(int x, int y) {
            int pX = find(x);
            int pY = find(y);
            if(pX == pY) return;
            
            if(ranks[pX] > ranks[pY]) {
                parents[pX] = pY;
            } else if(ranks[pX] < ranks[pY]) {
                parents[pY] = pX;
            } else {
                parents[pX] = pY;
                ranks[pY]++;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet DS(edges.size());
        for(vector<int> edge : edges) {
            int x = edge[0], y = edge[1];
            if(DS.find(x) == DS.find(y)) return edge;
            DS.uni(x, y);
        }
        return {};
    }
};