class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int e_sum = 0;
        int d_sum = 0;
        
        for(int num : nums) {
            e_sum += num;
            while(num) {
                d_sum += num % 10;
                num /= 10;
            }
        }
        
        return abs(e_sum - d_sum);
    }
};