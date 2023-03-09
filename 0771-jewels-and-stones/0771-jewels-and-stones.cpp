class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> j(jewels.begin(), jewels.end());
        int result = 0;
        for(char s : stones) {
            if(j.count(s)) result++;
        }
        return result;
        
    }
};