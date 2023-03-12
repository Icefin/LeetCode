class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return x;
        int left = 1, right = x;
        while (left <= right) {
            long long mid = (right) + (left - right) / 2;
            if (mid * mid  == x)
                return mid;
            else if (mid * mid > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};