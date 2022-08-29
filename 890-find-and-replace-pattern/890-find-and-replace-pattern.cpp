class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(auto word : words) {
            bool valid = true;
            
            unordered_map<char, char> patternMap1;
            unordered_map<char, char> patternMap2;
            for(int i = 0; i < word.size(); i++) {
                char wc = word[i];
                char pc = pattern[i];

                if(!patternMap1[wc]) patternMap1[wc] = pc;
                if(!patternMap2[pc]) patternMap2[pc] = wc;

                if(patternMap1[wc] != pc || patternMap2[pc] != wc) {
                    valid = false;
                    break;
                };
            }
            
            if(valid) result.push_back(word);
            
        }
        
        return result;
        
    }
};