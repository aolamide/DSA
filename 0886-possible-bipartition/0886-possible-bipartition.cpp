class Solution {
public:
    vector<int> parents;
    vector<int> ranks;
    
    int find(int x) {
        if(x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }
    
    void uni(int x, int y) {
        int parX = find(x);
        int parY = find(y);
        
        if(parX == parY) return;
        
        if(ranks[parX] > ranks[parY]) {
            parents[parY] = parX;
        } else if(ranks[parY] > ranks[parX]) {
            parents[parX] = parY;
        } else {
            parents[parY] = parX;
            ranks[parX]++;
        }
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n);
        parents = vector<int>(n);
        ranks = vector<int>(n, 1);
        
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        for(auto& dislike : dislikes) {
            adjList[dislike[0] - 1].push_back(dislike[1] - 1);
            adjList[dislike[1] - 1].push_back(dislike[0] - 1);
        }
        
        for(int i = 0; i < n; i++) {
            for(int ngh : adjList[i]) {
                if(find(i) == find(ngh)) return false;
                uni(adjList[i][0], ngh);
            }
        }
        return true;
    }
};