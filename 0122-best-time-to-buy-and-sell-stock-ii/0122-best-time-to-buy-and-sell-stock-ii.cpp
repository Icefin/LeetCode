class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_price = 1e9;
        int profit = 0;
        
        for (int price : prices) {
            if (min_price > price) {
                res += profit;
                profit = 0;
                min_price = price;
                continue;
            }
            
            if (price - min_price > profit) {
                profit = price - min_price;
                continue;
            }
            
            res += profit;
            profit = 0;
            min_price = price;
        }
        res += profit;
        return res;
    }
};