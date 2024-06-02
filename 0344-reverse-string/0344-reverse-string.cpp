class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int half = n * 0.5;
        
        for (int i = 0; i < half; ++i) {
            char temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }
    }
};