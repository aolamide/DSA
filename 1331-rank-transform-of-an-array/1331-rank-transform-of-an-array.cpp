class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArray(arr);
        sort(sortedArray.begin(), sortedArray.end());
        
        unordered_map<int, int> mp;
        int rank = 1;
        for(int i = 0; i < sortedArray.size(); i++) {
            if(i > 0 && sortedArray[i] != sortedArray[i - 1]) {
                mp[sortedArray[i]] = ++rank;
            } else {
                mp[sortedArray[i]] = rank;
            }
        }
        
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        
        return arr;
    }
};