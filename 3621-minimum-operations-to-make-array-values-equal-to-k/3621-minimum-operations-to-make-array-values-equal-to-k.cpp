class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        unordered_set<int> s;
        //we need to return how many distinct integers are greater than k.
        for(int num : nums) {
            //if a number in nums is less than k, it is impossible - return -1
            if(num < k) return -1;

            if(!s.count(num) && num > k) result++;
            s.insert(num);
        }
        return result;
    }
};