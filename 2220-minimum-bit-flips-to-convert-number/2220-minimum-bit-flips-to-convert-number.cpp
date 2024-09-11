class Solution {
public:
    int minBitFlips(int start, int goal) {
        int bit = start ^ goal;
        int res = 0;
        while (bit > 0) {
            res += bit % 2 == 1 ? 1 : 0;
            bit /= 2;
        }
        return res;
    }
};