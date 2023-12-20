class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = 101;
        int second = 101;
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] <= first) {
                second = first;
                first =  prices[i];
            }
            else if (prices[i] < second)
                second = prices[i];
        }        
        
        if (first + second <= money)
            return money - (first + second);
        return money;
    }
};