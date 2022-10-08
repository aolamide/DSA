class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i < n;i++) {
            // for(int a : nums) cout << a << " ";
            // cout << endl;
            int num = nums[i] % n;;
            
            if (num == 0) num = n;

            if (nums[num-1] > n) res.push_back(num);
            else nums[num-1] += n;
            
            
            
        }
        
        return res;
    }
};