class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int currCount = 0;
        int result = 0;
        
        for(int i = 0; i < k; i++) {
            if(vowels.count(s[i])) currCount++;
        }
        
        result = currCount;
        
        for(int i = k; i < s.size(); i++) {
            if(vowels.count(s[i - k])) currCount--;
            if(vowels.count(s[i])) currCount++;
            
            result = max(currCount, result);
            
        }
        
        return result;
    }
};