class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        
        int len = s.length();
        for (int start = 0; start < len; ++start) {
            for (int i = 0; i < len; ++i) {
                int j = (start + i) % len;
                if (s[j] != goal[i])
                    break;
                
                if (i == len - 1)
                    return true;
            }
        }
        return false;
    }
};