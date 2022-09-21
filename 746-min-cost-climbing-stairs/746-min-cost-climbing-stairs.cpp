// class Solution {
//     vector<int> c;
//     vector<int> dp;
// private:
//     int minCost(int i) {
//         if(i < 2) return c[i];
        
//         if(dp[i]) return dp[i];
        
//         int mc = c[i] + min(minCost(i - 1), minCost(i - 2));
        
//         dp[i] = mc;
        
//         return mc;
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         cost.push_back(0);
//         c = cost;
        
//         dp = vector<int>(cost.size(), 0);
        
//         return minCost(cost.size() - 1); 
//     }
// };

//optimised
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[1];
        int prev2 = cost[0];
        
        for(int i = 2; i < cost.size(); i++) {
            int tmp = prev1;
            
            prev1 = cost[i] + min(prev1, prev2);
            
            prev2 = tmp;
        }
        
        return min(prev1, prev2);
    }
};