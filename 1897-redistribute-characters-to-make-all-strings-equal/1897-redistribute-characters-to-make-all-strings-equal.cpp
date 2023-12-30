class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int alpha[26];
        memset(alpha, 0, sizeof(alpha));
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                alpha[words[i][j] - 'a']++;
            }
        }
        
        for (int i = 0; i < 26; ++i) 
            if (alpha[i] % words.size() != 0)
                return false;
        return true;
    }
};