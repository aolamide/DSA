class Solution {
public:
    bool buddyStrings(string s, string goal) {
        //if different length, not possible
        if(s.size() != goal.size()) return false;

        bool hasCharOccuringMoreThanOnce = false;
        unordered_map<char, int> sCharMap;
        unordered_map<char, int> goalCharMap;

        int countDifferingChars = 0;
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] != goal[i]) countDifferingChars++;
            if(countDifferingChars > 2) return false;

            sCharMap[s[i]]++;
            goalCharMap[goal[i]]++;

            if(sCharMap[s[i]] > 1) hasCharOccuringMoreThanOnce = true;
        }

        //check strings contain some frequency for all chars
        for(auto& m : sCharMap) {
            if(sCharMap[m.first] != goalCharMap[m.first]) return false;
        }


        //if strings are equal, and any char occurs more than once, swap can happen
        if(s == goal && hasCharOccuringMoreThanOnce) return true;

        //chars in different positions must be two
        return countDifferingChars == 2;
    }
};

//just need to check if both strings containe same frequency of all letters AND s[i] != goals[i] in two positions.
//edge case: if both are equal, but have a character occuring more than once, then swap is possible. e.g baa => baa can happen by swapping the a's