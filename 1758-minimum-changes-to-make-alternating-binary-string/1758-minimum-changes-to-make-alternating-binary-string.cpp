class Solution {
public:
    int minOperations(string s) {
        int len = s.length();
        
        int evenCnt = 0;
        for (int i = 0; i < len; ++i) {
            if (i % 2 == 0 && s[i] == '0')
                evenCnt++;
            else if (i % 2 == 1 && s[i] == '1')
                evenCnt++;
        }
        
        int oddCnt = 0;
        for (int i = 0; i < len; ++i) {
            if (i % 2 == 0 && s[i] == '1')
                oddCnt++;
            else if (i % 2 == 1 && s[i] == '0')
                oddCnt++;
        }
        return min(evenCnt, oddCnt);
    }
};