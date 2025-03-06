class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int duplicate, missing = 0;
        int n = grid.size() * grid.size();
        int expectedSum = (n * (n + 1)) / 2;
        unordered_set<int> s;

        int actualSum = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                int num = grid[i][j];
                if(!s.count(num)) {
                    s.insert(num);
                    actualSum += num;
                } else {
                    duplicate = num;
                }
            }
        }

        missing = expectedSum - actualSum;
        return {duplicate, missing};
    }
};

//sum of numbers from 1 to n^2 = (n * (n + 1)) / 2;
//use set to locate duplicate
//find sum of all numbers in grid, but don't add the second duplicate.
//missing number is expectedSum - actualSum