class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smallerList;
        vector<int> equalList;
        vector<int> greaterList;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) {
                smallerList.push_back(nums[i]);
            } else if(nums[i] > pivot) {
                greaterList.push_back(nums[i]);
            } else {
                equalList.push_back(pivot);
            }
        }
        
        result.reserve( smallerList.size() + equalList.size() + greaterList.size() );
        
        result.insert( result.end(), smallerList.begin(), smallerList.end() );
        result.insert( result.end(), equalList.begin(), equalList.end() );
        result.insert( result.end(), greaterList.begin(), greaterList.end() );
        
        return result;
    }
};