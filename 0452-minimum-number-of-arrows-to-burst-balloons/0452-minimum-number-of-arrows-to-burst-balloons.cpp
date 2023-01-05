class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        vector<int> lastInterval = points[0];
        int count = 1;
        
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] <= lastInterval[1]) {
                lastInterval[1] = min(points[i][1], lastInterval[1]);
            } else {
                count++;
                lastInterval = points[i];
            }
        }
        
        return count;
    }
};