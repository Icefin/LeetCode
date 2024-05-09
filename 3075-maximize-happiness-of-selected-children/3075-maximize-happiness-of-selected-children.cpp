class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int n = happiness.size();
        
        int select = 0;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            if (happiness[i] <= select || select == k)
                break;
            res += happiness[i] - select;
            select++;
        }
        return res;
    }
};