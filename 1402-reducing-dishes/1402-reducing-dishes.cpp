class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int pos_sum = 0;
        int neg_sum = 0;
        for (int i = 0; i < satisfaction.size(); i++) {
            if (satisfaction[i] > 0)
                pos_sum += satisfaction[i];
            else
                neg_sum += satisfaction[i];
        }
        
        int ans = 0;
        int t = 1;
        for (int i = 0; i < satisfaction.size(); i++) {
            if (satisfaction[i] < 0) {
                neg_sum -= satisfaction[i];
                if (satisfaction[i] * (-t) - neg_sum < pos_sum ) {
                    ans += satisfaction[i] * t;
                    t++;
                }
            }
            else {
                ans += satisfaction[i] * t;
                t++;
            }
        }
        return (ans);
    }
};