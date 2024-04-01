class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                res = 0;
                while (i < s.length() && s[i] != ' ') {
                    res++;
                    i++;
                }
            }
        }
        return res;
    }
};