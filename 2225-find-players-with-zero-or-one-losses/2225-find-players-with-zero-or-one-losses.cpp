class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loses;
        
        for(int i = 0; i < matches.size(); i++) {
            loses[matches[i][0]] += 0;
            loses[matches[i][1]] += 1;
        }
        vector<vector<int>> result(2);
        
        for(auto loss : loses) {
            if(loss.second == 0) result[0].push_back(loss.first);
            if(loss.second == 1) result[1].push_back(loss.first);
        }
        
        return result;
    }
};