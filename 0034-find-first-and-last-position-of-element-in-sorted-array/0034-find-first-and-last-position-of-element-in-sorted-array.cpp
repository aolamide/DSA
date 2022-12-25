class Solution {
private:
    int binarySearch(vector<int>& nums, int left, int target, bool first) {
        int ans = -1;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if(nums[mid] == target) {
                ans = mid;
                if(first) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            else if(nums[mid] > target) right = mid - 1;
            
            else left = mid + 1;
        }
        
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, 0, target, true);
        if(first == -1) return {-1,-1};
        
        int second = binarySearch(nums, first, target, false);
        
        return { first, second };
        
    }
};