class Solution {
private:
    vector<int> ch;
    unordered_set<int> seen;
public:
    void dfs(int node, vector<vector<int>>& adjList, string& labels, vector<int>& result) {
        if(seen.count(node)) return;
        
        int beforeCount = ch[labels[node] - 'a'];
        seen.insert(node);
        
        for(int n : adjList[node]) {
            dfs(n, adjList, labels, result);
            
        }

        ch[labels[node] - 'a']++;

        result[node] = ch[labels[node] - 'a'] - beforeCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ch = vector<int>(26, 0);
        vector<vector<int>> adjList(n);
        vector<int> result(n);
        for(vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        dfs(0, adjList, labels, result);
        
        return result;
    }
};