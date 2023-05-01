class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for (auto word : words) {
            for (int i = 0; i < text.length(); i++) {
                if (compare(text, word, i)) {
                    res.push_back({i, i + (int)word.length() - 1});
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    
private :
    bool compare(const string& s1, const string& s2, int idx) {
        int i = 0;
        for (; i + idx < s1.length() && i < s2.length(); i++) {
            if (s1[idx + i] != s2[i]) {
                return false;
            }
        }
        if (i != s2.length()) {
            return false;
        }
        return true;
    }
};