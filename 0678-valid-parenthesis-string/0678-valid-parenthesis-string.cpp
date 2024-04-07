class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        for (char c : s) {
            open += (c == '(') ? 1 : -1;
            close += (c != ')') ? 1 : -1;
            if (close < 0)
                return false;
            open = max(open, 0);
        }
        return (open == 0);
    }
};