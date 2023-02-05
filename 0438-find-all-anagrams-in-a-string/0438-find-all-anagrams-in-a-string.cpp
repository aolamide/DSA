class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> result;
        vector<int> pv (26, 0);
        for (auto c : p) pv[c - 'a']++;
        vector<int> sv (26, 0);
        
        int l = 0, r = 0;
        while (r < s.size()) {
            
            sv[s[r]-'a']++;
            if (r - l + 1 == p.size() && pv == sv)  result.push_back(l);
            if (r - l + 1 < p.size()) r++;
            
            else {
                sv[s[l]-'a']--;
                l++;
                r++;
            }
            
        }
        return result;
    }
};