class DS {
public:
    vector<int> parents;
    vector<int> sizes;
    
    DS(int size) {
        parents = vector<int>(size);
        sizes = vector<int>(size, 1);
        iota(parents.begin(), parents.end(), 0);
    }
    
    int find(int x) {
        if(x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }
    
    void Union(int x, int y) {
        int xP = find(x);
        int yP = find(y);
        
        if(xP == yP) return;
        
        if(sizes[xP] > sizes[yP]) {
            parents[yP] = xP;
            sizes[xP] += sizes[yP];
        } else {
            parents[xP] = yP;
            sizes[yP] += sizes[xP];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        
        DS DisjointSet = DS(stones.size());
        
        for(int i = 0; i < stones.size(); i++) {
            int row = stones[i][0];
            int col = stones[i][1];
            if(rows.count(row)) {
                DisjointSet.Union(i, rows[row]);
            } else {
                rows[row] = i;
            }
            
            if(cols.count(col)) {
                DisjointSet.Union(i, cols[col]);
            } else {
                cols[col] = i;
            }
        }

        int result = 0;
        for(int i = 0; i < stones.size(); i++) {
            int parent = DisjointSet.find(i);
            result += DisjointSet.sizes[parent] - 1;
            DisjointSet.sizes[parent] = 1;
        }
        
        return result;
    }
};