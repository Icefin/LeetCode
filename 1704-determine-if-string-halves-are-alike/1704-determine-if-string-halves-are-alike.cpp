class Solution {
public:
    bool halvesAreAlike(string s) {
        int half = s.length() / 2;
        int cnt = 0;
        
        for (int i = 0; i < half; ++i) {
            if (isVowel(s[i]) == true)
                cnt++;
            if (isVowel(s[i + half]) == true)
                cnt--;
        }
        return (cnt == 0);
    }
    
private :
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};