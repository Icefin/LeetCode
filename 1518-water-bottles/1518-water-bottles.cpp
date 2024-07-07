class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return floor((numBottles * numExchange - 1) / (numExchange - 1));
    }
};