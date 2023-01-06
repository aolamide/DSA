class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        for(int cost : costs) {
            coins -= cost;
            if(coins >= 0) result++;
            else return result;
        }
        
        return result;
    }
};