class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1, mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (((long long)spells[i] * potions[mid]) >= success)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            res.push_back(m - left);
        }
        return (res);
    }
};