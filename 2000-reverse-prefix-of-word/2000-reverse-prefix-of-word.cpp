class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == ch) {
                idx = i;
                break;
            }
        }
        
        if (idx != -1) {
            string prefix = word.substr(0, idx + 1);
            reverse(prefix.begin(), prefix.end());
            return prefix + word.substr(idx + 1);
        }
        return word;
    }
};