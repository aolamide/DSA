class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void dfs(vector<vector<int>>& graph, int start, int end) {
        path.push_back(start);
        
        if(start == end) {
            result.push_back(path);
        }
        
        for(int node : graph[start]) {
            dfs(graph, node, end);
        }
        
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size() - 1);
        
        return result;
    }
};