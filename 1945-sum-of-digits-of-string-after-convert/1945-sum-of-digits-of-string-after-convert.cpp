class Solution {
public:
    int getLucky(string s, int k) {
        const char value[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8};
        int res = 0;
        int strlen = s.length();
        for (int i = 0; i < strlen; ++i)
            res += value[s[i] - 'a'];
        
        while (k > 1) {
            int sum = 0;
            while (res > 0) {
                sum += res % 10;
                res /= 10;
            }
            res = sum;
            k--;
        }
        
        return res;
    }
};