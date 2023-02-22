class Solution {
public:
    int check(vector<int> &v, int w, int d){
        int count = 1;
        int sum = 0;
        for(auto i : v){
            sum += i;
            if(sum > w) sum = i, count++;
        }
        return count <= d;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(), weights.end());
       int high = accumulate(weights.begin(), weights.end(), 0);
        
        int ans = high;
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(check(weights, mid, days)) high = mid - 1, ans = mid;
            else low = mid + 1;
        }
        return ans;
    }
};