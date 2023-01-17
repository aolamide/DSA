class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int result = 0;
        int count = 0;
        for(char ch : s) {
            if(ch == '1') count++;
            
            else result = min(result + 1, count);
        }
        return result;
    }
};