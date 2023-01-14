class Solution {
public:
    vector<int> parents;
        
    int find(int x) {
        if(x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }
    
    void uni(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if(pX == pY) return;
        
        if(pX < pY) {
            parents[pY] = pX;
        } else {
            parents[pX] = pY;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parents = vector<int>(26, 0);
        iota(parents.begin(), parents.end(), 0);
        string result;
        for(int i = 0; i < s1.size(); i++) {
            uni(s1[i] - 'a', s2[i] - 'a');
        }
        
        for(int i = 0; i < baseStr.size(); i++){
            result += (char)(find(baseStr[i] - 'a') + 'a');
        }
        
        return result;
    }
};