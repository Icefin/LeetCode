class Solution {
public:
    string customSortString(string order, string s) {
        uint8_t priority[26];
        memset(priority, -1, sizeof(priority));
        for (int i = 0; i < order.length(); ++i) {
            priority[order[i] - 'a'] = i + 1;
        }
        
        sort(s.begin(), s.end(), [&](char c1, char c2) {
            return priority[c1 - 'a'] < priority[c2 - 'a'];
        });
        return s;
    }
};