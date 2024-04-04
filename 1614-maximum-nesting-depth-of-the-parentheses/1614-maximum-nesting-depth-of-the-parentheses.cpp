class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int depth = 0;
        for (const char& c : s) {
            if (c == '(')
                depth++;
            else if (c == ')')
                depth--;
            
            res = max(res, depth);
        }
        return res;
    }
};