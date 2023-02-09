class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        
        int sum = duration;
        for(int i = 0; i < timeSeries.size() - 1 ; ++i) {
            sum += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return sum;
    }
};