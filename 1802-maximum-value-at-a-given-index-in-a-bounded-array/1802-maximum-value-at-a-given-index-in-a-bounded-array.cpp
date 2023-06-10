class Solution {
public:
   int maxValue(int n, int index, int maxSum) {
    int res = 1;
    int left = index;
    int right = index;
    
    maxSum = maxSum - n;

    while (left > 0 || right < n - 1) {
        int len = right - left + 1;
        if (maxSum < len) {
            break;
        }
        
        maxSum = maxSum - len;
        res++;
        left = max(0, left - 1);
        right = min(n - 1, right + 1);
    }
    res += (maxSum / n);
    return res;
    }
};