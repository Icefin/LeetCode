class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
    
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = n - 1; i >= 0; --i) {
            int currMax = 0;
            int end = min(n, i + k);

            for (int j = i; j < end; ++j) {
                currMax = max(currMax, arr[j]);
                dp[i] = max(dp[i], dp[j + 1] + currMax * (j - i + 1));
            }
        }
        return dp[0];
    }
};