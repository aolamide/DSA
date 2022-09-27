class Solution {
public:
    int dfs(int node, vector<vector<int>>& adjList, vector<int>& quiet, vector<int>& result) {
        
        if(result[node] != -1) return result[node];
        
        vector<int> adjs = adjList[node];
        
        int ansNode = node;
        int ans = quiet[node];
        
        for(int adj : adjs) {
            int resultNode  = dfs(adj, adjList, quiet, result);
            if(ans > quiet[resultNode]) {
                ansNode = resultNode;
                ans = quiet[resultNode];
            }
        }
        
        result[node] = ansNode;
        
        return result[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjList(n);
        
        for(vector<int> edge : richer) {
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> result(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(result[i] == -1) {
                dfs(i, adjList, quiet, result);
            }
        }
        
        return result;
    }
};