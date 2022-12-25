class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> prefSum(nums.size(), 0);
        prefSum[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        vector<int> ans;
        
        for(int i = 0; i < queries.size(); i++) {
            int target = queries[i];
            
            int l = 0, r = prefSum.size() - 1;
            
            while(l <= r) {
                int mid = l + (r - l)/2;
                
                if(prefSum[mid] <= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            ans.push_back(l);
        }
        
        return ans;
    }
};