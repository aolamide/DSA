class Solution {
public:
    bool rec(string& num, int n, unordered_set<string>& s) {
        if(num.size() == n) {
            if(!s.count(num)) {
                return true;
            } 
            return false;
        }
        
        for(char i = '0'; i <= '1'; i++) {
            num += i;
            if(rec(num, n, s)) return true;
            num.pop_back();
        }
        
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> s;
        for(string num : nums) s.insert(num);
        string str = "";
        rec(str, n, s);
        return str;
    }
};