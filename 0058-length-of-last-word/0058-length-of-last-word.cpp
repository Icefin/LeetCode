class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                ans = 0;
                while (i < s.length() && s[i] != ' ') {
                    ans++;
                    i++;
                }
            }
        }
        return ans;
    }
};