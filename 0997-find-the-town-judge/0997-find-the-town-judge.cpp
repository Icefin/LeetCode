class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> bucket(n + 1, 0);
        vector<bool> isJudge(n + 1, true);
        
        for (int i = 0; i < trust.size(); ++i) {
            bucket[trust[i][1]]++;
            isJudge[trust[i][0]] = false;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (isJudge[i] == true && bucket[i] == n - 1)
                return i;
        }
        return -1;
    }
};