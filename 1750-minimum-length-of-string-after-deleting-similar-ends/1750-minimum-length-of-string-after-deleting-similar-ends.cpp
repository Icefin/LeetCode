class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            char target = s[l];
            if (s[r] != target)
                break;
            
            while (s[l] == target && l <= r)
                l++;
            while (s[r] == target && l <= r)
                r--;
        }
        return r - l + 1;
    }
};