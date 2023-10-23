class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;
        return (n && !(n & (n - 1)) && !(n & 0xAAAAAAAA));
    }
};