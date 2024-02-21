class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int bit = 0;
        while (left < right) {
            left = (left >> 1);
            right = (right >> 1);
            bit++;
        }
        return (right << bit);
    }
};
