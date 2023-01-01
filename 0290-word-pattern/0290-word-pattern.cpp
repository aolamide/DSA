class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        istringstream ss(s);
        string word;
            
        while (ss >> word) words.push_back(word);
        
        if(words.size() != pattern.size()) return false;
        
        unordered_map<string, char> mpWC;
        unordered_map<char, string> mpCW;
        
        for(int i = 0; i < pattern.size(); i++) {
            if(!mpWC[words[i]]) mpWC[words[i]] = pattern[i];
            if(!mpCW.count(pattern[i])) mpCW[pattern[i]] = words[i];
            
            if(mpWC[words[i]] != pattern[i] || mpCW[pattern[i]] != words[i]) return false;
        }
        
        return true;
        
    }
};