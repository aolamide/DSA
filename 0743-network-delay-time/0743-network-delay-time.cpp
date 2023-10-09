class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n);
        
        // [
        //   0 [ [1,2], [2,4] ],
        //   1 [ [2,5] ]
        // ]
        
        for(vector<int> time : times) {
            adj[time[0] - 1].push_back({ time[1] - 1, time[2] });
        }
        
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k - 1});
        
        
        vector<int> distances(n, INT_MAX);
        distances[k - 1] = 0;
        
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            
            for(vector<int> child : adj[curr[1]]) {
                int newDist = child[1] + curr[0];
                if(newDist < distances[child[0]]) {
                    distances[child[0]] = newDist;
                    pq.push({ distances[child[0]], child[0] });
                }                
            }
            
        }
        
        
        int result = INT_MIN;
        
        for(int dist : distances) {
            result = max(result, dist);
        }
        
        if(result == INT_MAX) return -1;
        
        return result;
    }
};