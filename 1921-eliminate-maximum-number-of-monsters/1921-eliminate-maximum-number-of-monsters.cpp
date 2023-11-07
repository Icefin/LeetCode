class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n  = dist.size();
        vector<int> arrive(n);
        for (int i = 0; i < n; ++i)
            arrive[i] = ceil((double)dist[i] / speed[i]);
        sort(arrive.begin(), arrive.end());
        
        for (int i = 0; i < n; ++i) {
            if (arrive[i] <= i)
                return (i);
        }
        return n;
    }
};