class Solution {
    vector<int> c;
    vector<int> dp;
private:
    int minCost(int i) {
        if(i < 2) return c[i];
        
        if(dp[i]) return dp[i];
        
        int mc = c[i] + min(minCost(i - 1), minCost(i - 2));
        
        dp[i] = mc;
        
        return mc;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        c = cost;
        
        dp = vector<int>(cost.size(), 0);
        
        return minCost(cost.size() - 1); 
    }
};