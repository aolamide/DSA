class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string k = countAndSay(n - 1);
        string res;
        int count = 1;
        for(int i = 0; i < k.size(); i++) {
            if(k[i] == k[i + 1]) count++;
            else {
                res += to_string(count) + k[i];
                count = 1;
            }
        }
        return res;
    }
};