class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = candies[0];
        
        for(int candyCount : candies) maxCandy = max(candyCount, maxCandy);

        vector<bool> result;
        for(int candyCount : candies) {
            if(candyCount + extraCandies >= maxCandy) result.push_back(true);
            else result.push_back(false);
        }
        
        return result;
    }
};