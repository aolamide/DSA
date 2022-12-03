class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(char ch : s) mp[ch]++;
        
        priority_queue<pair<int, char>> pq;
        
        for(auto c : mp) {
            pq.push({c.second, c.first});
        }
        
        string result = "";
        
        while(!pq.empty()) {
            int n = pq.top().first;
            while(n-- > 0) result += pq.top().second;
            pq.pop();
        }
        
        return result;
    }
};