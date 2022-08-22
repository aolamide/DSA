class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        double i;
        return modf(log10(n)/log10(4), &i) == 0.0;
    }
};