// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<vector<int>>> adjList(n);
        
//         //build adjancency list
//         for(vector<int> time : times) {
//             adjList[time[0] - 1].push_back({time[1] - 1, time[2]});
//         }
        
//         //Dijstra's algorithm
//         vector<int> shortest(n, INT_MAX);
//         shortest[k - 1] = 0;
        
//         priority_queue<pair<int,int>> pq;
//         pq.push(make_pair(0, k - 1));
        
//         while(!pq.empty()) {
//             auto curr = pq.top();
//             pq.pop();
            
//             vector<vector<int>> nodes = adjList[curr.second];
            
//             for(vector<int> node : nodes) {
//                 int newDist = shortest[curr.second] + node[1];
//                 if(newDist < shortest[node[0]]) {
//                     shortest[node[0]] = newDist;
//                     pq.push(make_pair(-1 * newDist, node[0]));
//                 }
//             }
//         }
        
//         int result = 0;
        
//         for(int val : shortest) {
//             result = max(val, result);
//         }
        
//         if(result == INT_MAX) return -1;
//         return result;
//     }
// };


//BellMan Ford Algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> paths(n, INT_MAX);
        paths[k - 1] = 0;
        
        for(int i = 0; i < n - 1; i++) {
            bool noUpdate = true;
            
            for(vector<int> time : times) {
                int source = time[0] - 1;
                int target = time[1] - 1;
                int weight = time[2];
                
                if(paths[source] == INT_MAX) continue;
                int cost = paths[source] + weight;
                
                if(cost < paths[target]) {
                    paths[target] = cost;
                    noUpdate = false;
                }
            }
            
            if(noUpdate) break;
        }
        
        int result = 0;
        
        for(int val : paths) {
            result = max(val, result);
        }
        
        if(result == INT_MAX) return -1;
        
        return result;
       
    }
};