class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); //O(nlogn)

        vector<vector<int>> result;

        int lastVal = INT_MIN;

        //O(n^2)
        for(int i = 0; i < n - 2; i++) { //O(n)
            if(nums[i] > 0) return result;
            if(nums[i] == lastVal) continue;
            lastVal = nums[i];

            int target = 0 - nums[i];
            int p1 = i + 1;
            int p2 = n - 1;

            while(p1 < p2) { //O(n)
                int sum = nums[p1] + nums[p2];
                if(sum == target) {
                    result.push_back({ nums[i], nums[p1], nums[p2] });
                    int num1 = nums[p1];
                    while(p1 < n && nums[p1] == num1) p1++;

                } else if(sum < target) {
                    p1++;
                } else {
                    p2--;
                }
            }
        }

        return result;
    }
};