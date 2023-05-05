class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                cnt++;
        }
        res = cnt;
        int left = 0, right = k;
        for (; right < s.length(); right++) {
            if (isVowel(s[left])) cnt--;
            if (isVowel(s[right])) cnt++;
            res = max(res, cnt);
            left++;
        }
        return res;
    }
    
private :
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};