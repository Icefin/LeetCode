class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alpha_maga[26];
        int alpha_rans[26];
        memset(alpha_maga, 0, sizeof(alpha_maga));
        memset(alpha_rans, 0, sizeof(alpha_rans));
        
        for (char c : magazine)
            alpha_maga[c - 'a']++;
        for (char c : ransomNote)
            alpha_rans[c - 'a']++;
        
        for (int i = 0; i < 26; ++i)
            if (alpha_rans[i] > alpha_maga[i])
                return false;
        return true;
    }
};