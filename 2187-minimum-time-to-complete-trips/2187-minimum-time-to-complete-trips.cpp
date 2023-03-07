class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l= 0,r = totalTrips * (long long)time[0], ans = r;
        while(l < r){
            long long mid= l + (r - l)/2;
            long long count=0;
            for(int i = 0;i < time.size(); i++){
                count += mid/time[i];
            } 
            if(count >= totalTrips){
                ans = min(ans, mid);
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};