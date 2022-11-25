class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;

        stack<int> s;

        vector<int> dp(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            if (s.size() > 0) {
                int previousSmaller = s.top();
                dp[i] = dp[previousSmaller] + (i - previousSmaller) * arr[i];
            } else {
                dp[i] = (i + 1) * arr[i];
            }
            s.push(i);
        }

        long sumOfMinimums = 0;
        
        
        
        for (int count : dp) {
            sumOfMinimums += count;
            sumOfMinimums %= MOD;
        }

        return (int) sumOfMinimums;
    }
};