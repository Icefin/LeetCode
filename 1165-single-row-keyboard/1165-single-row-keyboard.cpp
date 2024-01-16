class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int keycode[26];
        for (int i = 0; i < 26; ++i)
            keycode[keyboard[i] - 'a'] = i;
        
        int res = 0;
        int finger = 0;
        for (int i = 0; i < word.length(); ++i) {
            int next = keycode[word[i] - 'a'];
            res += abs(finger - next);
            finger = next;
        }
        return res;
    }
};