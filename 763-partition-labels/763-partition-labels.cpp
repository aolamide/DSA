class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOcMap;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(!lastOcMap[s[i]]) {
                lastOcMap[s[i]] = i;
            }
        }

        int p1 = 0;
        int p2 = 0;
        int tmp = 0;

        vector<int> result;

        while(p1 < s.size()) {
            if(lastOcMap[s[p1]] > p2) {
                p2 = lastOcMap[s[p1]];
            }

            if(p2 == s.size() - 1) {
                result.push_back(p2 - tmp + 1);
                break;
            }

            if(p1 == p2) {
                result.push_back(p2 - tmp + 1);
                p2++;
                tmp = p2;
            };

            p1++;
        }

        return result;
    }
};