class Solution {
public:
    string makeGood(string s) {
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            if (res.length() == 0)
                res += s[i];
            else if (res.back() == s[i] - 32 || res.back() == s[i] + 32)
                res.pop_back();
            else
                res += s[i];
        }
        return res;
    }
};