class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n = word1.length();
        int m = word2.length();
        for (int i = 0; i < n + m; i++) {
            if (i >= 2 * n) {
                res += word2[i - n];
            }
            else if (i >= 2 * m) {
                res += word1[i - m];
            }
            else {
                res += i % 2 == 0 ? word1[i / 2] : word2[i / 2];
            }
        }
        return res;
    }
};