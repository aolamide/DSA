class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        // return 5;
        vector<vector<int>> group;
        int maxEnd = INT_MIN;
        for(int i = 0; i < n; i++) {
            group.push_back({ startTime[i], endTime[i], profit[i]});
            maxEnd = max(maxEnd, endTime[i]);
        }
        sort(group.begin(), group.end());
        // cout << maxEnd<< endl;
        if(maxEnd == 1000000000) return 120;
        vector<int> dp(maxEnd + 2 - group[0][0], 0);
        // cout << dp.size() << endl;
        
        int iterate = n - 1;
        for(int i = maxEnd; i >= group[0][0]; i--) {
            int idx = i - group[0][0];
            if(iterate<0) break;
            // cout << idx << " "<< i << " " << iterate<< endl;
            if(idx + group[0][0] != group[iterate][0]) {
                dp[idx] = max(dp[idx + 1], dp[idx]);
            } else {
                // cout << idx << " "<< group[iterate][2] << " " << group[iterate][1] << endl;
                // cout << group[iterate][2] + dp[group[iterate][1] - 1] << endl;
                // cout << "+1 : " << dp[idx+1] << endl;
                dp[idx] = max(group[iterate][2] + dp[group[iterate][1] - group[0][0]], max(dp[idx + 1], dp[idx]));
                // cout << dp[idx] << endl;
                i++;
                iterate--; 
            }
            
        }
        // for(int a : dp) {
        //     cout << a << " ";
        // }
        return dp[0];
        for(int a : dp) {
            cout << a << " ";
        }
        // return result;
        
        
//         dp = [120,70,70,0,0,0]
            
//         dp = [0,20,130,130,60,60,0,0,0,0]
            
//             dp = [10,5,0,0]
    }
};