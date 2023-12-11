class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        
        for (int r = n / 4; r < n; ++r) {
            if (arr[l] == arr[r])
                return arr[l];
            ++l;
        }
        return 0;
    }
};