class Solution {
public:
    string revWord(string& str) {
        string result = "";
        result += str[1];
        result += str[0];
        return result;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int count = 0;
        
        for(auto word : words) {
            string rev = revWord(word);
            
            if(mp[rev]) {
                mp[rev]--;
                count += 4;
            } else {
                mp[word]++;
            }
        }
        
        for(auto x : mp) {
            string word = x.first;
            string rev = revWord(word);
            
            if(x.second > 0 && x.first == rev) {
                count += 2;
                break;
            }
        }
        
        return count;
    }
};