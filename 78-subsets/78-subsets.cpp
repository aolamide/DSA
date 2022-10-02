class Solution {
public:
    int n, k;
    vector<vector<int>> result;
    
    void backtrack(int start, vector<int>& curr, vector<int>& nums) {
        if(curr.size() == k) {
            result.push_back(curr);
            return;
        }
        
        for(int i = start; i < n; i++) {
            curr.push_back(nums[i]);
            
            backtrack(i + 1, curr, nums);
            
            curr.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        
        for(k = 0; k < n + 1; k++) {
            backtrack(0, curr, nums);
        }
        
        return result;
    }
};