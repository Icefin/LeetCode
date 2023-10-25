class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1)
            return 0;
        else if (k % 2 == 1)
            return kthGrammar(n - 1, (k + 1) / 2);
        else
            return !kthGrammar(n - 1, k / 2);
    }
};

//                0110100110010010
//                              01
//                            0110
//                        01101001
//                0110100110010110
//01101001100101101001011001101001

