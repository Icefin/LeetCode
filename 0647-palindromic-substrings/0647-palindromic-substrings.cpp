class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= len - i; ++j) {
                if (isPalindromic(s.substr(i, j)) == true) {
                    res++;
                }
            }
        }
        return res;
    }
    
private:
    bool isPalindromic(const string& s) {
        int len = s.length();
        int half = len / 2;
        for (int i = 0; i < half; ++i) {
            if (s[i] != s[len - 1 - i])
                return false;
        }
        return true;
    }
};