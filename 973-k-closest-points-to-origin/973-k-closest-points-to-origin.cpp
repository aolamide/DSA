class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < points.size(); i++) {
            pq.push(make_pair(-1 * (pow(points[i][0],2) + pow(points[i][1], 2)), i));
        }
        
        vector<vector<int>> result;
        
        for(int i = 0; i < k; i++) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return result;
    }
};