class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> sums;
        int alice = 0;
        int bob = 0;
        for(int i = 0; i < n; i++) {
            sums.push_back(make_pair(aliceValues[i] + bobValues[i], i));
        }
        
        sort(sums.begin(), sums.end());
        
        for(int i = n - 1; i >= 0; i -= 2) {
            int idx = sums[i].second;
            alice += aliceValues[idx];
        }
        
        for(int i = n - 2; i >= 0; i -= 2) {
            int idx = sums[i].second;
            bob += bobValues[idx];
        }
        
        if(alice == bob) return 0;
        else if(alice > bob) return 1;
        return -1;
    }
};