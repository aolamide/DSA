class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> result(n, 0);
        stack<pair<int, int>> s;
        s.push({temperatures[n - 1], n - 1});
        
        
        for(int i = n - 2; i >= 0; i--) {
            int curr = temperatures[i];
            while(!s.empty() && curr >= s.top().first) {
                s.pop();
            }
            if(!s.empty()) result[i] = s.top().second - i;
            s.push({curr, i});          
        }
        
        return result;
    }
};