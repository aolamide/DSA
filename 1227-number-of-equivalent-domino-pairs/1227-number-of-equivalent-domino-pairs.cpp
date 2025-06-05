class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> freq;
        int result = 0;

        for (auto& d : dominoes) {
            int a = d[0];
            int b = d[1];
            if (a > b) swap(a, b);

            string key = to_string(a) + "_" + to_string(b);
            result += freq[key];
            ++freq[key];
        }
        return result;
    }
};