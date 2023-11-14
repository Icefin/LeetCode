class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int len;
        int min_len = min(strs[0].size(), strs.back().size());
        for (len = 0; len < min_len; ++len) {
            if (strs[0][len] != strs.back()[len])
                break;
        }
        return strs[0].substr(0, len);
    }
};