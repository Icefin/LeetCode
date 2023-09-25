class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_alpha[27];
        int t_alpha[27];
        
        memset(s_alpha, 0, sizeof(s_alpha));
        memset(t_alpha, 0, sizeof(t_alpha));
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            s_alpha[s[i] - 'a']++;
            t_alpha[t[i] - 'a']++;
        }
        t_alpha[t[n] - 'a']++;
        for (int i = 0; i < 27; ++i)
            if (s_alpha[i] != t_alpha[i])
                return ('a' + i);
        return 0;
    }
};