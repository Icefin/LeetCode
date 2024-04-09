class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        while (true) {
            for (int i = 0; i < tickets.size(); ++i) {
                if (tickets[i] == 0)
                    continue;
                res++;
                tickets[i]--;
                if (tickets[k] == 0)
                    return res;
            }
        }
        return res;
    }
};