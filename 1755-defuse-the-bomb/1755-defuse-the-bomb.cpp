class Solution {
public:
//need optimizing
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size());

        for(int i = 0; i < code.size(); i++) {
            int sum = 0;
            int j = 1;
            if(k > 0) {
                while(j <= k) {
                    sum += code[(i + j) % code.size()];
                    j++;
                }
            } else if(k < 0) {
                while(j <= abs(k)) {   
                    sum += code[(i - j + code.size()) % code.size()];
                    j++;
                }
            }

            result[i] = sum;
        }

        return result;
    }
};