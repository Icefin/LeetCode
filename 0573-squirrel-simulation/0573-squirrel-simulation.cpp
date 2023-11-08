class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int n = nuts.size();
        vector<int> squirrel_to_nuts(n);
        vector<int> tree_to_nuts(n);
        
        for (int i = 0; i < n; ++i) {
            squirrel_to_nuts[i] = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
            tree_to_nuts[i] = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
        }
        
        int tot_dist = 2 * std::accumulate(tree_to_nuts.begin(), tree_to_nuts.end(), 0);
        int min_dist = 1e9;
        for (int i = 0; i < n; ++i) {
            int curr_dist = tot_dist - tree_to_nuts[i] + squirrel_to_nuts[i];
            if (curr_dist < min_dist)
                min_dist = curr_dist;
        }
        return (min_dist);
    }
};