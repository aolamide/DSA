class Solution {
public:
    unordered_map<int, int> quietMap;
    int dfs(int node, vector<vector<int>>& adjList, vector<int>& quiet, vector<int>& result) {
        
        if(result[node] != -1) return result[node];
        
        vector<int> adjs = adjList[node];
        
        int ans = quiet[node];
        
        for(int adj : adjs) {
            ans = min(ans, quiet[dfs(adj, adjList, quiet, result)]);
        }
        
        result[node] = quietMap[ans];
        
        return result[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjList(n);
        
        for(int i = 0; i < n; i++) {
            quietMap[quiet[i]] = i;
        }
        
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