class Solution {
public:
    bool checkRecord(string s) {
        int absentDays = 0;
        int consecutiveLateDays = 0;

        for(char dayStatus : s) {
            if(dayStatus == 'L') {
                consecutiveLateDays++;
                if(consecutiveLateDays == 3) return false;
            }
            else {
                if(dayStatus == 'A') absentDays++;
                consecutiveLateDays = 0;
            }
        }

        return absentDays < 2;
    }
};