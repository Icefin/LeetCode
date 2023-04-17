class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int max_num = 0;
        
        for (auto candy : candies) {
            if (candy > max_num)
                max_num = candy;
        }
        
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= max_num) {
                ans[i] = true;
            }
        }
        return (ans);
    }
};