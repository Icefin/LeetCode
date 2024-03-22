class Solution {
public:
    string removeVowels(string s) {
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                continue;
            res += s[i];
        }
        return res;
    }
};