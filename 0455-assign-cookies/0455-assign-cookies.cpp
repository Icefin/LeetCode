class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int cidx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (g[cidx] > s[i])
                continue;
            
            cidx++;
            if (cidx == g.size())
                return g.size();
        }
        return cidx;
    }
};