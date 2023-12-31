class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> alpha(26, -1);
        
        int res = -1;
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i] - 'a';
            if (alpha[c] == -1) {
                alpha[c] = i;
            }
            else {
                res = max(res, i - alpha[c] - 1);
            }
        }
        return res;
    }
};