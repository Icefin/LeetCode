class Solution {
public:
    int minSteps(string s, string t) {
        int alpha[26];
        memset(alpha, 0, sizeof(alpha));
        
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            alpha[s[i] - 'a']++;
            alpha[t[i] - 'a']--;
        }
        
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (alpha[i] > 0)
                res += alpha[i];
        }
        return res;
    }
};