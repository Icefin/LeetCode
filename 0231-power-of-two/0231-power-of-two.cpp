class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == INT_MIN)
            return false;
        return (__builtin_popcount(n) == 1);
    }
};