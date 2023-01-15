class Solution {
public:
    // string curr = "";
    vector<int> result = {};
    void rec(int start, int diff, int n, string curr) {
        curr += to_string(start);
        
        if(n == 1) {
            result.push_back(stoi(curr));
            return;
        }

        int l = start - diff;
        int r = start + diff;
        if(l == r) return rec(l, diff, n-1, curr);

        if(l >= 0) rec(l, diff, n-1, curr);
        
        if(r < 10) rec(r, diff, n-1, curr);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++) {
            rec(i, k, n, "");
        }
        
        return result;
    }
};