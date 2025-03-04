class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.size() < name.size()) return false;

        int i = 0;
        int j = 0;

        while(i < name.size()) {
            if(name[i] != typed[j]) return false;

            char currChar = name[i];

            int currCharCount = 1;
            while(name[++i] == currChar && i < name.size()) {
                currCharCount++;
            }

            int currCharTypedCount = 1;
            while(typed[++j] == currChar && j < typed.size()) {
                currCharTypedCount++;
            }

            if(currCharTypedCount < currCharCount) return false;
        }

        //both pointers must be at end
        return i == name.size() && j == typed.size();
    }
};