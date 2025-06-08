class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),  nums.end());

        if(nums[0] + nums[1] <= nums[2]) return "none";

        unordered_map<int, int> sides;

        sides[nums[0]]++;
        sides[nums[1]]++;
        sides[nums[2]]++;

        if(sides.size() == 1) return "equilateral";

        if(sides.size() == 2) return "isosceles";

        return "scalene";
    }
};