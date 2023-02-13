class Solution {
public:
    int countOdds(int low, int high) {
        int count = high - low + 1;
        int result = count/2 + 1;
        if(count % 2 == 0 || low % 2 == 0) result -= 1;
        return result;
    }
};