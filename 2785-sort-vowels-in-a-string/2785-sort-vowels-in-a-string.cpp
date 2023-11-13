class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> um;
        
        for (char c : s) {
            if (is_vowel(c) == true)
                um[c]++;
        }
        
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (is_vowel(s[i]) == false)
                continue;
            
            for (int j = 0; j < 10; ++j) {
                if (um[str[j]] != 0) {
                    s[i] = str[j];
                    um[str[j]]--;
                    break ;
                }
            }
        }
        return s;
    }
    
private :
    string str = "AEIOUaeiou";
    bool is_vowel(char c) {
        for (int i = 0; i < 10; ++i) {
            if (c == str[i])
                return (true);
        }
        return false;
    }
};