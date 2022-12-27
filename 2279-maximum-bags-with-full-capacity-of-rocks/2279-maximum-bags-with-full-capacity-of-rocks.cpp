class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diffs;
        
        for(int i = 0; i < rocks.size(); i++) {
            diffs.push_back(capacity[i] - rocks[i]);
        }
        
        sort(diffs.begin(), diffs.end());
        
        int count = 0;
        for(int diff : diffs) {
            if(diff != 0) {
                additionalRocks -= diff;
                if(additionalRocks < 0) return count;
            }
            count++;
        }
        
        return count;
    }
};