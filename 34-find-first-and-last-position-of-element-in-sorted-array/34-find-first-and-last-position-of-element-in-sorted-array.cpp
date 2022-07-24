class Solution {
private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while(left <= right) {
            int mid = (left + right) / 2;
            int numMid = nums[mid];
            cout << numMid << "\t";
            if(numMid == target) return mid;
            else if(numMid > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int firstFound = binarySearch(nums, target, l, r);
        if(firstFound == -1) return {-1,-1};
        
        int start = firstFound, end = firstFound;
        int tmpStart, tmpEnd;
        
        while(start != -1) {
            tmpStart = start;
            start = binarySearch(nums, target, l, start - 1);
        }
        start = tmpStart;
        
        while(end != -1) {
            tmpEnd = end;
            end = binarySearch(nums, target, end + 1, r);
        }
        end = tmpEnd;
        
        return {start , end};
    }
};