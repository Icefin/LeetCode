class Solution {
public:
    int partitionString(string s) {
        bool isDuplicated[26];
        memset(isDuplicated, false, sizeof(isDuplicated));
        
        int ans = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isDuplicated[s[i] - 'a']) {
                ans++;
                memset(isDuplicated, false, sizeof(isDuplicated));
                isDuplicated[s[i] - 'a'] = true;
                continue ;
            }
            isDuplicated[s[i] - 'a'] = true;
        }
        return (ans);
    }
};