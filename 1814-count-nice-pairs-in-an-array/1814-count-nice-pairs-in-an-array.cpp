class Solution {
public:
    int reverseNum(int num) {
        if(num == 0) return 0;
        int pw = log10(num);
        int rNum = 0;
        while(pw >= 0) {
            int val = num % 10;
            rNum += val * pow(10, pw);
            num /= 10;
            pw--;
        }
        return rNum;
    }
    int countNicePairs(vector<int>& nums) {
        int MOD = pow(10, 9) + 7;
        vector<int> copy;
        int count = 0;
        unordered_map<int, int> numMap;
        for(auto num : nums) {
            int newVal = num - reverseNum(num);
            if(numMap[newVal]) {
                count += numMap[newVal];
                count %= MOD;
            }
            numMap[newVal]++;
        }
        return count;
    }
};