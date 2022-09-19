class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> adjList(numCourses);
        
        for(vector<int> p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        
        stack<int> s;
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) s.push(i);
        }
        
        vector<int> result;
        
        while(!s.empty()) {
            int curr = s.top();
            s.pop();
            result.push_back(curr);
            vector<int> children = adjList[curr];
            
            for(int c : children) {
                if(--inDegree[c] == 0) s.push(c);
            }
        }
        
        if(result.size() == numCourses) return result;
        
        return {};
    }
};