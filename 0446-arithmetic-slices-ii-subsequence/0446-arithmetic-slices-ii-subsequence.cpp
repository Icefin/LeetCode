class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                
                dp[i][diff]++;
                if (dp[j].count(diff) != 0) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        return res;
    }
};