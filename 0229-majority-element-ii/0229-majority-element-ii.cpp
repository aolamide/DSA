class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
                if(nums.size() == 1) return nums;

                int cap = nums.size() / 3;
                int nums1 = INT_MAX, nums2 = INT_MAX, c1 = 0, c2 = 0;

                for(int num : nums) {
                    if(num == nums1) {
                        c1++;
                    } else if(num == nums2) {
                        c2++;
                    }
                    else if(c1 == 0) {
                        nums1 = num;
                        c1 = 1;
                    } else if(c2 == 0) {
                        nums2 = num;
                        c2 = 1;
                    } else {
                        c1--;
                        c2--;
                    }
                }

                c1 = 0, c2 = 0;
                for(int num : nums) {
                    if(num == nums1) c1++;
                    if(num == nums2) c2++;
                }

                vector<int> result;
                if(c1 > cap) result.push_back(nums1);
                if(c2 > cap) result.push_back(nums2);

                return result;
    }
};