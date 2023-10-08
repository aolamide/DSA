class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for(char ch : s) {
            if(st.empty() || st.top().first != ch) {
                st.push({ ch, 1 });
            } else {
                pair<char, int> top = st.top();
                st.pop();
                if(top.second != k - 1) st.push({ ch, top.second + 1 });
            }
        }
        
        string result = "";
        
        while(!st.empty()) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};