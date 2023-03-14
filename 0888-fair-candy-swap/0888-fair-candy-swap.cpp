class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int as = 0, bs = 0;
        for(int x : aliceSizes) as += x;
        for(int x : bobSizes) bs += x;
        int diff = (bs - as) / 2;
        
        unordered_set<int> s;
        for(int x : bobSizes) s.insert(x);
        
        for(int x : aliceSizes) {
            if(s.count(x + diff)) return { x, x + diff};
        }
        
        return {0, 0};
    }
};