class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();
        vector<int> prefix(n, 0);
        
        prefix[0] = travel[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + travel[i];
        
        //M, P, G
        vector<int> last_idx(3, 0);
        int garbage_accum = 0;
        n = garbage.size();
        for (int i = 0; i < n; ++i) {
            string garb = garbage[i];
            
            int len = garb.length();
            garbage_accum += len;
            for (int j = 0; j < len; ++j) {
                if (garb[j] == 'M')
                    last_idx[0] = i;
                else if (garb[j] == 'P')
                    last_idx[1] = i;
                else if (garb[j] == 'G')
                    last_idx[2] = i;
            }
        }
        
        int m_dist = (last_idx[0] == 0) ? 0 : prefix[last_idx[0] - 1];
        int p_dist = (last_idx[1] == 0) ? 0 : prefix[last_idx[1] - 1];
        int g_dist = (last_idx[2] == 0) ? 0 : prefix[last_idx[2] - 1];
        return garbage_accum + m_dist + p_dist + g_dist;
    }
};