class Solution {
    //time complexity = o(nlogn)
    //space complexity = o(1)
public:
    int compress(vector<char>& chars) {
        int count = 1;
        char lastChar = chars[0];
        int idx = 0;

        //push a char that is not the last char (to help handle last char count in loop)
        char endChar = chars[chars.size() - 1];
        chars.push_back(char( int(endChar) + 1 ));

        for(int i = 1; i < chars.size(); i++) {
            if(chars[i] == lastChar) {
                count++;
                continue;
            }
            else if(count == 1) {
                idx += 1;  
            }
            else {
                int countLen = log10(count) + 1;
                int n = countLen;
                while(count) {
                    chars[idx + n] = to_string(count % 10)[0];
                    count /= 10;
                    n--;
                }
                count = 1;
                
                idx += countLen + 1;

                chars[idx] = chars[i];
            }
            
            chars[idx] = chars[i];
            lastChar = chars[i];
        }
        

        return idx;
    }
};