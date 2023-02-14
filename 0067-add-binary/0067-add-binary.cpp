class Solution {
public:
    string addBinary(string a, string b) {
        int p1 = a.size() - 1;
        int p2 = b.size() - 1;
        string ans;
        
        int carry = 0;
        
        while(p1 >= 0 || p2 >= 0){
            int sum = carry;
            
            if(p1 >= 0) sum += a[p1] - '0';
            
            if(p2 >= 0) sum += b[p2] - '0';
            
            carry = sum > 1 ? 1 : 0;
            
            ans += to_string(sum % 2);
            p1--;
            p2--;
        }
        if(carry) ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};