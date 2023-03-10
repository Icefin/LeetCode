class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1, max = 1e9;
        int ans;
        while (min <= max) {
            int mid = (min + max) / 2;
            long long sum = 0;
            for (int i = 0; i < piles.size(); i++) {
                sum += piles[i] / mid;
                sum += (piles[i] % mid) == 0 ? 0 : 1;
            }

            if (sum <= h) {
                max = mid - 1;
                ans = mid;
            }
            else {
                min = mid + 1;
            }
        }
        return (ans);
    }
};