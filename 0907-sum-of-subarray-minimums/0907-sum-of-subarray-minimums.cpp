class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {  
        stack<int> st;
      
        int n = arr.size();
        vector<int> dp(n);
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            while (st.empty() == false && arr[st.top()] >= arr[i]) {
                st.pop();
            }
                
        
            if (st.empty() == false) {
                int prev = st.top();
                dp[i] = dp[prev] + (i - prev) * arr[i];
            }
            else {
                dp[i] = (i + 1) * arr[i];
            }
            sum = (sum + dp[i]) % MOD;
            st.push(i);
        }
        return sum;
    }
};