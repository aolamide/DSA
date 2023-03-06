class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] - mid - 1 < k) l = mid + 1;
            else r = mid;
        }
        return l + k;
    }
};