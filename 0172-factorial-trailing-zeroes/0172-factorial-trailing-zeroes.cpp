class Solution {
public:
    int trailingZeroes(int n) {
        int two_cnt = 0, five_cnt = 0;
        
        for (int i = 2; i <= n; ++i) {
            int num = i;
            while (num % 2 == 0 || num % 5 == 0) {
                if (num % 2 == 0) {
                    two_cnt++;
                    num /= 2;
                }
                if (num % 5 == 0) {
                    five_cnt++;
                    num /= 5;
                }   
            }
        }
        
        return min(two_cnt, five_cnt);
    }
};