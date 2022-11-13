class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream st(s);
        
        string tmp_str;
        
        while (st >> tmp_str) {
            words.push_back(tmp_str);
        }

        string result;
        
        result += words[words.size() - 1];
        
        for (int i = words.size() - 2; i >= 0; --i) {
            result += " " + words[i];
        };
        
        return result;
    }
};