class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> new_arr;
        int i = 0;
        while(i < n) {
            new_arr.push_back(nums[i]);
            new_arr.push_back(nums[i++ + n]);
        }
        return new_arr;
    }
};