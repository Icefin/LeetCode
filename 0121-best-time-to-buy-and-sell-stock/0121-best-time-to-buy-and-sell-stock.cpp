class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min = prices[0];
        
        for (int price : prices) {
            if (price - min > res)
                res = price - min;
            if (price < min)
                min = price;
        }
        return (res);
    }
};