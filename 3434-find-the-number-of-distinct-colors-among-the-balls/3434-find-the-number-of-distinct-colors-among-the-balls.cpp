class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;

        //store frequency of colors.
        unordered_map<int, int> colorFrequencies;
        //store color of each ball.
        unordered_map<int, int> ballColors;

        for(vector<int> query : queries) {
            int ball = query[0];
            int color = query[1];

            //if ball previously had a color. Reduce current color frquency.
            if(ballColors.count(ball)) {
                int currColor = ballColors[ball];
                colorFrequencies[currColor]--;
                //if current color frquency goes to zero, clear from map.
                if(!colorFrequencies[currColor]) colorFrequencies.erase(currColor);
            }
            ballColors[ball] = color;
            colorFrequencies[color]++;

            //store count of distinct colors.
            result.push_back(colorFrequencies.size());
        }

        return result;
    }
};