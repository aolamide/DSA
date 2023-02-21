class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            int mid = l + (r - l)/2;
            // cout << l << " " << mid << " " << r << endl;
            if(mid % 2 == 0) {
                if(mid > 0 && nums[mid - 1] == nums[mid]) {
                    r = mid - 1;
                } else if(nums[mid + 1] != nums[mid]) {
                    return nums[mid];
                } 
                else {
                    l = mid + 1;
                }
            } else {
                if(mid < nums.size() && nums[mid + 1] == nums[mid]) {
                    r = mid - 1;
                }
                else if(nums[mid - 1] != nums[mid]) return nums[mid];
                else l = mid + 1;
            }
        }
        // cout << l << " " << r;
        return nums[l];
    }
};
// [1,2,2,3,3]