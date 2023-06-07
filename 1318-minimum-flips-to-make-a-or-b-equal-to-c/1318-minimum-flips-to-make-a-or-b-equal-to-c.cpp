class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        int bitSum = (a | b);
        int upper_limit = max(a, max(b, c));
        for (int i = 1; i <= upper_limit; i = (i << 1)) {
            if ((bitSum & i) == (c & i)) {
                continue;
            }
            
            if ((bitSum & i) == 0) {
                res++;
                continue;
            }
            res += (a & i) == 0 ? 0 : 1;
            res += (b & i) == 0 ? 0 : 1;
        }
        return res;
    }
};

//1'000'000'000