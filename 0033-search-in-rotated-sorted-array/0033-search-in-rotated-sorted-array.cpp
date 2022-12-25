class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < nums[l]) {
                //array is rotated, and mid is in right part
                if(nums[r] < target || nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else  {
                //array is rotated and mid is in left part OR fully sorted array
                if(nums[l] <= target && nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
        }
        
        return -1;
    }
};