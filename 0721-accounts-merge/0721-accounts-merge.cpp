class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> adjList;
        unordered_map<string, string> namesMap;
        vector<vector<string>> result;
        
        for(int i = 0; i < accounts.size(); i++) {
            string last = accounts[i][1];
            string name = accounts[i][0];
            
            for(int j = 1; j < accounts[i].size(); j++) {
                string curr = accounts[i][j];
                if(!adjList.count(curr)) {
                    adjList[curr] = {};
                    namesMap[curr] = name;
                }
                if(last != curr){
                    adjList[last].insert(curr);
                    adjList[curr].insert(last);
                }
            }
        }
        unordered_set<string> seen;
        
        for(auto edge : adjList) {
            if(seen.count(edge.first)) continue;
            queue<string> q;
            vector<string> sub;
            q.push(edge.first);
            sub.push_back(namesMap[edge.first]);
            
            while(!q.empty()) {
                string curr = q.front();
                q.pop();
                seen.insert(curr);
                sub.push_back(curr);
                for(string ngh : adjList[curr]) {
                    if(!seen.count(ngh)) {
                        q.push(ngh);
                        seen.insert(ngh);
                    }
                }
            }
            sort(sub.begin() + 1, sub.end());
            result.push_back(sub);
        }
        
        
        // for(auto list : adjList) {
        //     cout << list.first << " : " ;
        //     for(auto em : list.second) {
        //         cout << em << ", ";
        //     }
        //     cout << endl;
        // }
        
        return result;
        // [["David","David0@m.co","David4@m.co","David3@m.co"],["David","David5@m.co","David5@m.co","David0@m.co"],["David","David1@m.co","David4@m.co","David0@m.co"],["David","David0@m.co","David1@m.co","David3@m.co"],["David","David4@m.co","David1@m.co","David3@m.co"]]
        
        //[["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]
    }
};