class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        unordered_set<int> used;
        
        backtrack(1, n, used);
        
        return count;
    }
    void backtrack(int idx, int n, unordered_set<int>& used) {
        if(idx == n + 1) {
            count++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(used.count(i)) continue;
            if((idx % i == 0) || (i % idx == 0)) {
                used.insert(i);
                backtrack(idx + 1, n, used);
                used.erase(i);
            }
        }
    }
};