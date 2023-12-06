class Solution {
public:
    int totalMoney(int n) {
        int div = n / 7;
        int mod = n % 7;
        
        return mod * (mod + 1) / 2 + 28 * div + 7 * div * (div - 1) / 2 + div * mod;
    }
};