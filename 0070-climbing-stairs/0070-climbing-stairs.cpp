class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int pprev = 1;
        int res = 1;
        
        for (int i = 2; i <= n; ++i) {
            res = prev + pprev;
            pprev = prev;
            prev = res;
        }
        return res;
    }
};