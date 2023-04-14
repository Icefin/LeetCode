class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        return recursive(s, 0, n - 1, dp);
    }

    int recursive(string& s, int left, int right, vector<vector<int>>& dp) {
        if (dp[left][right] != 0) {
            return dp[left][right];
        }
        if (left > right) {
            return 0;
        }
        if (left == right) {
            return 1;
        }

        if (s[left] == s[right]) {
            dp[left][right] = recursive(s, left + 1, right - 1, dp) + 2;
        } else {
            dp[left][right] = max(recursive(s, left + 1, right, dp), recursive(s, left, right - 1, dp));
        }
        return dp[left][right];
    }
};