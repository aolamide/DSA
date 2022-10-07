class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adjList(n);
        
        for(auto flight : flights) {
            adjList[flight[0]].push_back({ flight[1], flight[2] });
        }
        
        vector<int> dist(n, INT_MAX);
        // shortest[src] = 0;
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        pq.push({ 0, src, 0 });
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int currNode = curr[1];
            int currCost = curr[0];
            int currStops = curr[2];
            
            if(currNode == dst) return currCost;
            
            if(dist[currNode] < currStops) continue;
            dist[currNode] = currStops;
            
            vector<vector<int>> ngbrs = adjList[curr[1]];

            if(currStops <= k) {
                for(auto ngbr : ngbrs) {
                    int newCost = ngbr[1] + currCost;
                    pq.push({ newCost, ngbr[0], currStops + 1 });
                }
            }
        }
        
        return -1;
        
    }
};