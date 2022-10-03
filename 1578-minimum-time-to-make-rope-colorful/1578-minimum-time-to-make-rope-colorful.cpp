class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        
        int maxColor = neededTime[0];
        int runningSum = neededTime[0];
        int colorCount = 1;
        
        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[i - 1]) {
                maxColor = max(maxColor, neededTime[i]);
                runningSum += neededTime[i];
                colorCount++;
            } else {
                result += runningSum - maxColor;
                runningSum = neededTime[i];
                maxColor = neededTime[i];
                colorCount = 1;
            }
        }
        
        result += runningSum - maxColor;
        
        return result;
    }
};