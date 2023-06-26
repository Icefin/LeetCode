class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0;
        int left = 0, right = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> lpq, rpq;
        for (int i = 0; i < candidates; i++) {
            lpq.push(costs[left++]);
            rpq.push(costs[right--]);
            if (left >= right)
                break;
        }
        
        while (k > 0) {
            if (left > right)
                break;
            
            if (lpq.top() <= rpq.top()) {
                res += lpq.top(); lpq.pop();
                lpq.push(costs[left++]);
            }
            else {
                res += rpq.top(); rpq.pop();
                rpq.push(costs[right--]);
            }
            k--;
        }
        
        while (k > 0) {
            if (rpq.empty()) {
                res += lpq.top(); lpq.pop();
            }
            else if (lpq.empty()) {
                res += rpq.top(); rpq.pop();
            }
            else if (lpq.top() <= rpq.top()) {
                res += lpq.top(); lpq.pop();
            }
            else {
                res += rpq.top(); rpq.pop();
            }
            k--;
        }
        return res;
    }
};