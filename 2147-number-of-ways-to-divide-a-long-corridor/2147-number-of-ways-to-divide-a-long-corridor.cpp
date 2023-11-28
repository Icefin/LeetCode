class Solution {
public:
    int numberOfWays(string corridor) {
        vector<vector<int>> intervals;
        
        vector<int> v = {-1, -1};
        int len = corridor.length();
        for (int i = 0; i < len; ++i) {
            if (corridor[i] == 'P')
                continue;

            if (v[0] == -1)
                v[0] = i;
            else if (v[1] == -1)
                v[1] = i;
            
            if (v[1] != -1) {
                intervals.push_back(v);
                v = {-1, -1};
            }
        }
        
        if (intervals.size() == 0 || (v[0] != -1 && v[1] == -1))
            return 0;
        
        long long res = 1;
        int n = intervals.size();
        for (int i = 0; i < n - 1; ++i) {
            res = res * (intervals[i + 1][0] - intervals[i][1]) % (1000000007);
        }
        return res;
    }
};