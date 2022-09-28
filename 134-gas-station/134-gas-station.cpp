class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //start from every gas station, and attempt to get back to it

        int totalCost = 0;

        int unit = 0;

        int ans = 0;

        for(int i = 0; i < gas.size(); i++) {
            totalCost += gas[i] - cost[i];
            
            unit += gas[i] - cost[i];

            if(unit < 0) {
                unit = 0;
                ans = i + 1;
            }
            
            
        }

        if(totalCost < 0) return -1;
        

        return ans;
    }
};
//space : O(1)
//time : O(N) where N = no. of stations