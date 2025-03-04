class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freqMap;

        for(char s: word) {
            freqMap[s]++;   
        }

        //map frequency counts to how many times they occur
        unordered_map<int, int> frequencyCount;
        for(auto& [_, freq] : freqMap) {
            frequencyCount[freq]++;
        }
        if(frequencyCount.size() > 2) return false;

        int lowerFreqOccurence = INT_MAX;
        int higherFreqOccurence = INT_MIN;

        for(auto& [freq, _] : frequencyCount) {
            lowerFreqOccurence = min(lowerFreqOccurence, freq);
            higherFreqOccurence = max(higherFreqOccurence, freq);
        }

        //if we only have one size. return true if higher frequency occurence is 1 (as in abcde, abc, feg) OR count of higher frequency occurences is 1 ( as in zz, ccc, aaaa)
        if(frequencyCount.size() == 1) return higherFreqOccurence == 1 || frequencyCount[higherFreqOccurence] == 1; 

        //now if difference between higher frequency occurence and lower frequency occurence is 1, and count of higher frequency occurences is 1, we retur true (as in ddffgghhh)
        if((higherFreqOccurence - lowerFreqOccurence == 1) && frequencyCount[higherFreqOccurence] == 1) return true;

        //Finally if lower frequency occurence is 1 and its count is 1 (as in aaabbbcccd, eeffggh), retur true
        if(frequencyCount[lowerFreqOccurence] == 1 && lowerFreqOccurence == 1) return true;


        return false;
    }
};