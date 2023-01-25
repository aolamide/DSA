class Solution {
public:
    void bfs(int start, vector<int>& edges, vector<int>&distances) {
        queue<int> q;
        q.push(start);
        
        int count = 0;
        while(!q.empty()) {
            int curr = q.front();
            if(distances[curr] != INT_MAX) break;
            q.pop();
            distances[curr] = count++;
            
            if(edges[curr] > -1) q.push(edges[curr]);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);
        
        int result_dist = INT_MAX;
        int result_idx = -1;
        for(int i = 0; i < n; i++) {
            if(dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;
            
            int dist = max(dist1[i], dist2[i]);
            
            if(dist < result_dist) {
                result_dist = dist;
                result_idx = i;
            }
        }
        
        return result_idx;
    }
};