class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> orderMap;
        int ord = 1;
        for(auto o : order) {
            if(!orderMap[o]) orderMap[o] = -1 * ord++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto c : s) {
            pq.push(make_pair(orderMap[c], c));
        }
        
        string result;
        
        while(!pq.empty()) {
            result += pq.top().second;
            pq.pop();
        }
        
        return result;
    }
};