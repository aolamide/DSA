class Solution {
private:
    int numSoldiers(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int count = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;
            
            if(arr[mid] == 1) {
                count = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return count;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < mat.size(); i++) {
            int soldiers = numSoldiers(mat[i]);
            arr.push_back({soldiers, i});
        }
        sort(arr.begin(), arr.end());
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(arr[i].second);
        }
        
        return result;
    }
};