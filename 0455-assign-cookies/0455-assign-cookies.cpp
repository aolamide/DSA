class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int p1 = 0;
        int p2 = 0;
        int result = 0;
        
        while(p1 < g.size() && p2 < s.size()) {
            if(g[p1] <= s[p2]) {
                result++;
                p1++;
                p2++;
            } else {
                p2++;
            }
        }
        
        return result;
    }
};