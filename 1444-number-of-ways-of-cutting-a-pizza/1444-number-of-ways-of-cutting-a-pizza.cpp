int mod = 1e9+7;
int apples[51][51];
int dp[51][51][11];

class Solution {
public:
    int m, n;

    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        for (int i = m - 1; i >= 0; i--) {
            apples[i][n - 1] = (pizza[i][n - 1] == 'A');
            for (int j = n - 2; j >= 0; j--) {
                apples[i][j] = (pizza[i][j] == 'A') ? apples[i][j + 1] + 1 : apples[i][j + 1];
            }
            if (i == m - 1) continue;
            for (int j = n - 1; j >= 0; j--) {
                apples[i][j] += apples[i + 1][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        return recursive(0, 0, k-1);
    }

    int recursive(int i, int j, int cut) {
        if (cut == 0)
            return apples[i][j] > 0;
        if (apples[i][j] < cut + 1) {
            dp[i][j][cut] = 0;
            return 0;
        }
        if (dp[i][j][cut] != -1)
            return dp[i][j][cut];
        
        int res = 0;
        for (int ni = i + 1; ni < m; ni++) {
            if (apples[i][j] > apples[ni][j])
                res = (res + recursive(ni, j, cut - 1)) % mod;
        }
        for (int nj = j + 1; nj < n; nj++) {
            if (apples[i][j] > apples[i][nj])
                res = (res + recursive(i, nj, cut - 1)) % mod;
        }
        dp[i][j][cut] = res;
        return res;
    }
};

//Cutting order is not important
//How to save the path regardless of order?
//How to find at least one apple on each pieceses