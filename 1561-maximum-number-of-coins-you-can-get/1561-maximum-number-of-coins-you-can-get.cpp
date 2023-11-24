class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin() , piles.end(), greater<int>());
        
        int res = 0;
        int p = 1;
        int n = piles.size() / 3;
        for (int i = 0; i < n; ++i) {
            res += piles[p];
            p += 2;
        }
        return res;
    }
};