class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0, 1};
        
        vector<unordered_set<int>> adjList(n);
        
        for(vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(adjList[i].size() == 1){
                q.push(i);
            } 
        }
        
        int removedNodes = 0;
        int levelCount = q.size();
        vector<int> result;
        
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            removedNodes++;
            
            for(const int& node : adjList[val]) {
                adjList[node].erase(val);
                if(adjList[node].size() == 1) q.push(node);
            }
            
            //use -1 to denote last level. add values to result from last level.
            if(levelCount == -1) {
                result.push_back(val);
            }
            else if(levelCount - 1 == 0) {
                if(removedNodes >= n - 2) {
                    levelCount = -1;
                } else {
                    levelCount = q.size();
                }
            } else {
                levelCount--;
            }
        }
        
        return result;
    }
};