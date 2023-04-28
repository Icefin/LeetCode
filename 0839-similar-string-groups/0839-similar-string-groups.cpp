class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int res = 0;
        int n = strs.size();
        vector<bool> isUnioned(n, false);
        for (int i = 0; i < n; i++) {
            if (isUnioned[i]) {
                continue;
            }
            res++;
            isUnioned[i] = true;
            dfs(i, isUnioned, strs);
        }
        return res;
    }
    
private :
    void dfs(int idx, vector<bool>& isUnioned, vector<string>& strs) {
        string s1 = strs[idx];
        for (int i = 0; i < strs.size(); i++) {
            if (isUnioned[i]) {
                continue;
            }
            string s2 = strs[i];
            if (isSimilar(s1, s2)) {
                isUnioned[i] = true;
                dfs(i, isUnioned, strs);
            }
        }
    }
    
    bool isSimilar(string s1, string s2) {
        int n = s1.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                cnt++;
            }
            if (cnt > 2) {
                return false;
            }
        }
        return true;
    }
};