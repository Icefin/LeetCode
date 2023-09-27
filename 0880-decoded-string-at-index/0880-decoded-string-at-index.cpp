class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        
        for (char c : s) {
            if (isalpha(c) != false)
                size++;
            else {
                size *= c - '0';
            }
        }
        
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            k %= size;
            if (k == 0 && isalpha(s[i]) != 0)
                return (string(1, s[i]));
            
            if (isdigit(s[i]) != 0)
                size /= s[i] - '0';
            else
                size--;
        }
        return "";
    }
};