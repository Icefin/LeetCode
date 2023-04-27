class Solution {
public:
    int bulbSwitch(int n) {
        int leastSquareNum = getLeastSquareNum(n);
        return sqrt(leastSquareNum);
    }
    
private :
    int getLeastSquareNum(int n) {
        while (n > 1) {
            if (sqrt(n) == (int)sqrt(n)) {
                return n;
            }
            n--;
        }
        return n;
    }
};