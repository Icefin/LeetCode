class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int n = s.length();
        for (int i = 0; i < n - 1; ++i) {
            sum += abs(s[i + 1] - s[i]);
        }
        return sum;
    }
};