class Solution {
public:
    int dfs(int node, vector<vector<int>>& adjList, vector<int>& quiet, vector<int>& result) {
        
        if(result[node] != -1) return result[node];
        
        result[node] = node;
        
        for(int adj : adjList[node]) {
            int resultNode  = dfs(adj, adjList, quiet, result);
            if(quiet[result[node]] > quiet[resultNode]) {
                result[node] = resultNode;
            }
        }
        
        return result[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjList(n);
        
        //O(E)
        for(vector<int> edge : richer) {
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> result(n, -1);
        
        //O(V)
        for(int i = 0; i < n; i++) {
            if(result[i] == -1) {
                dfs(i, adjList, quiet, result);
            }
        }
        
        return result;
    }
};