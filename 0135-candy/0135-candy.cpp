class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
            else if (ratings[i] < ratings[i-1] && candies[i] >= candies[i-1]) {
                candies[i - 1] = candies[i] + 1;
            }
        }

        for (int j = ratings.size() - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1] && candies[j] <= candies[j + 1]) {
                candies[j] = candies[j + 1] + 1;
            }
            else if (ratings[j] < ratings[j + 1] && candies[j] >= candies[j + 1]) {
                candies[j + 1] = candies[j] + 1;
            }
        }
        
        int result = 0;
        for (int x : candies) result += x;
        
        return result;
    }
};