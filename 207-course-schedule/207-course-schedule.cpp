class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        
        int count = 0;
        
        while(!s.empty()) {
            int curr = s.top();
            s.pop();
            count++;
            vector<int> children = adjList[curr];
            
            for(int c : children) {
                if(--inDegree[c] == 0) s.push(c);
            }
        }
        
        return count == numCourses;
    }
};