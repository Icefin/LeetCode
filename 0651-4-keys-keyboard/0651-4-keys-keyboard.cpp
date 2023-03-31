class Solution {
public:
    int maxA(int n) {
        if (n <= 6)
            return (n);
        
        int res = 0;
        int prev = 6, pprev = 5, doub = 4, trip = 3, quad = 2;
        for(int i = 7; i <= n; i++)
        {
            res = max(2 * doub, max(3 * trip, 4 * quad));
            
            quad = trip;
            trip = doub;
            doub = pprev;
            pprev = prev;
            prev = res;
        }

        return (res);
    }
};