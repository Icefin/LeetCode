class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26];
        memset(alpha, -1, sizeof(alpha));
        for (int i = 0; i < s.length(); ++i) {
            if (alpha[s[i] - 'a'] == -1)
                alpha[s[i] - 'a'] = i;
            else if (alpha[s[i] - 'a'] != -1 )
                alpha[s[i] - 'a'] = -2;
        }
        int res = 1e9;
        for (int i = 0; i < 26; ++i) {
            if (alpha[i] == -1 || alpha[i] == -2)
                continue;
            res = min(res, alpha[i]);
        }
        return res == 1e9 ? -1 : res;
    }
};