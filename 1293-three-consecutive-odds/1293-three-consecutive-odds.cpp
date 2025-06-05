class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutive_odds = 0;

        for(int num : arr) {
            if(num % 2 == 0) {
                consecutive_odds = 0;
            } else {
                consecutive_odds++;
                if(consecutive_odds == 3) return true;
            }
        }

        return false;
    }
};