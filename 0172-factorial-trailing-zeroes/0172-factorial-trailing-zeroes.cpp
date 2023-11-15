class Solution {
public:
    int trailingZeroes(int n) {
       int five_cnt = 0;
       
        while(n / 5 > 0) {
            five_cnt += n / 5;
            n /= 5;
        }
        return five_cnt;
    }
};