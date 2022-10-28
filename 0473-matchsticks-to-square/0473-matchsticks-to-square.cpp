class Solution {
public:
    bool helper(vector<int>& fourSides, vector<int>& matchsticks, int size, int idx) {
        if(idx == -1) {
            return true;
        }

        for(int j = 0; j < 4; j++) {
            if(matchsticks[idx] + fourSides[j] <= size) {
                fourSides[j] += matchsticks[idx];

                if(helper(fourSides, matchsticks, size, idx - 1)) {
                    return true;
                }

                fourSides[j] -= matchsticks[idx];
            }
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        sort(matchsticks.begin(), matchsticks.end());
        int sum = 0;
        for(int m : matchsticks) sum += m;

        if(sum % 4 != 0) return false;

        vector<int> fourSides(4, 0);

        return helper(fourSides, matchsticks, sum/4, matchsticks.size() - 1);
    }
};