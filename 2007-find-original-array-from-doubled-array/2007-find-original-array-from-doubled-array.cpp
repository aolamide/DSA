class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr.size() & 1) return {};
        
        unordered_map<int,int> mp;
        vector<int>ans;
        int cnt = 0;
        for(auto x : arr){
            mp[x]++;
            if(x == 0) cnt++;      //to avoid the 0 multiplication factor
        }
        
        if(cnt & 1) return {};
        
        for(int i = 0;i < arr.size(); i++){
            if(mp[2*arr[i]] && mp[arr[i]]){
                ans.push_back(arr[i]);
                mp[2 * arr[i]]--;
                mp[arr[i]]--;
            }
        }
  
        if(ans.size() * 2 == arr.size()) return ans;
        
        return {};
    }
};