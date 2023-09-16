class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for(int num : nums1) s1.insert(num);
        
        unordered_set<int> s2;
        
        vector<int> uNums2;
        for(int num : nums2) {
            if(!s1.count(num) && !s2.count(num)) uNums2.push_back(num) ;
            s2.insert(num);
        }
        
        vector<int> uNums1;
        for(int num : s1) {
            if(s2.count(num)) continue;
            uNums1.push_back(num);
        }
        
        return {uNums1, uNums2};
    }
};