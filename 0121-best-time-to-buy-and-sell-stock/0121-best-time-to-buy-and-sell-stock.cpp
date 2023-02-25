class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int minP = prices[0];
        int profit = 0;
        
        for(int i = 1; i < n; i++) {
            profit = max(prices[i] - minP, profit);
            minP = min(minP, prices[i]);
        }
        
        return profit;
    }
};