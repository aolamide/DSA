class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> result;
//         int p1 = 0, p2 = 0;
        
//         while(p1 < m && p2 < n) {
//             if(nums1[p1] < nums2[p2]) {
//                 result.push_back(nums1[p1]);
//                 p1++;
//             } else {
//                 result.push_back(nums2[p2]);
//                 p2++;
//             }
//         }
        
//         while(p1 < m) {
//             result.push_back(nums1[p1]);
//             p1++;
//         }
//         while(p2 < n) {
//             result.push_back(nums2[p2]);
//             p2++;
//         }
        
//         nums1 = result;
        
        int k = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;
        
        while(p1 >= 0 && p2 >= 0) {
            if(nums1[p1] > nums2[p2]) {
                nums1[k] = nums1[p1];
                p1--;
            } else {
                nums1[k] = nums2[p2];
                p2--;
            }
            k--;
        }
        
        while(p2 >= 0) {
            nums1[k] = nums2[p2];
            p2--;
            k--;
        }
        
    }
};