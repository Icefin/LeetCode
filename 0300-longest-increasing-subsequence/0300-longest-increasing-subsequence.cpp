class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] != -1)
                continue;
            
            recursive(i, nums, dp);
            res = max(res, dp[i]);
        }
        return res;
    }
    
private :
    void recursive(int idx, vector<int>& nums, vector<int>& dp) {
        if (dp[idx] != -1)
            return ;

        for (int i = idx + 1; i < nums.size(); ++i) {
            if (nums[idx] < nums[i]) {
                recursive(i, nums, dp);
                dp[idx] = max(dp[idx], dp[i] + 1);
            }
        }
        dp[idx] = max(dp[idx], 1);
    }
};