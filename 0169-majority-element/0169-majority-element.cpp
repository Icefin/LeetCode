class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int res = arr[0];
        int cnt = 1;
        
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (cnt == 0) {
                res = arr[i];
                cnt = 1;
                continue;
            }
            cnt = (res == arr[i]) ? cnt + 1 : cnt - 1;
        }
        return (res);
    }
};