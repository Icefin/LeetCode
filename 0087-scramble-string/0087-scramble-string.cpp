class Solution {
public:
    unordered_map<string, bool> dp;

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (s1 == s2) {
            return true;
        }
        string key = s1 + "#" + s2;
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        int freq[26] = {0};
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                dp[key] = false;
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))) ||
                (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))) {
                dp[key] = true;
                return true;
            }
        }
        dp[key] = false;
        return false;
    }
};