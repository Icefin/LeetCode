class Solution {
public:
    string customSortString(string order, string s) {
        int frequency[26];
        memset(frequency, 0, sizeof(frequency));
        for (int i = 0; i < s.length(); ++i) {
            frequency[s[i] - 'a']++;
        }
        
        string res = "";
        for (int i = 0; i < order.length(); ++i) {
            res.append(frequency[order[i] - 'a'], order[i]);
            frequency[order[i] - 'a'] = 0;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (frequency[i] != 0) {
                res.append(frequency[i], 'a' + i);
            }
        }
        return res;
    }
};