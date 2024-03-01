class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length();
        int bitCnt = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '1')
                bitCnt++;
        }
        
        return string(bitCnt - 1, '1') + string(len - bitCnt, '0') + '1';
    }
};