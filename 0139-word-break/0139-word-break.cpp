class Solution {
public:
    bool rec(int start, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if(start == s.size()) {
            return true;
        }

        if(dp[start] > -1) return dp[start];

        for(int i = start + 1; i <= s.size(); i++) {
            if(dict.count(s.substr(start, i - start)) && rec(i, s, dict, dp)) {
                dp[start] = 1;
                return true;
            }
        }

        dp[start] = 0;

        return false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> dp(s.size(), -1);

        for(string word : wordDict) dict.insert(word);

        return rec(0, s, dict, dp);
        
    }
};