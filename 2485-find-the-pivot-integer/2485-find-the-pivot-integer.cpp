class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;

        int l = 1, r = n;
        while (l < r) {
            int pivot = l + (r - l) / 2;

            if (pivot * pivot < totalSum)
                l = pivot + 1;
            else
                r = pivot;
        }

        if (l * l == totalSum)
            return l;
        return -1;
    }
};