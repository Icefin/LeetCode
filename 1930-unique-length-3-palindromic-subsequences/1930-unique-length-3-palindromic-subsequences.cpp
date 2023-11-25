class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int alpha = s[i] - 'a';
            if (first[alpha] == -1) {
                first[alpha] = i;
            }
            last[alpha] = i;
        }
        
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1)
                continue;
            
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; ++j) {
                between.insert(s[j]);
            }
            res += between.size();
        }
        return res;
    }
};