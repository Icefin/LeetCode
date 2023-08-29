class Solution {
public:
    int bestClosingTime(string customers) {
        int numYes = 0;
        int endTime = customers.length();
        for (int t = 0; t < endTime; ++t)
            if (customers[t] == 'Y')
                numYes++;
        
        int bestClosingTime = 0;
        int minPenalty = 1e9;
        int cntYes = 0;
        for (int t = 0; t < endTime; ++t) {
            int penalty = (t - cntYes);
            penalty += (customers[t] == 'Y') ? numYes - cntYes + 1 : numYes - cntYes;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestClosingTime = t;
            }
            
            if (customers[t] == 'Y')
                cntYes++;
        }
        
        if (endTime - numYes < minPenalty)
            bestClosingTime = endTime;
        
        return bestClosingTime;
    }
};