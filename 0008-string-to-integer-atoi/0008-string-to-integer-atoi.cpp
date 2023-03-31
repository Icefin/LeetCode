class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int sign = 1;
        int ptr = 0;
        
        while (ptr < s.length() && s[ptr] == ' ')
            ptr++;
        if (s[ptr] == '+' || s[ptr] == '-') {
            if (s[ptr] == '-')
                sign = -1;
            ptr++;
        }
        while (ptr < s.length() && isdigit(s[ptr])) {
            res = (res * 10) + (s[ptr] - '0');
            if (res >= -(long long)INT_MIN) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ptr++;
        }
        return (sign * res);
    }
};