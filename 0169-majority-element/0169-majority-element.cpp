class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int res = arr[0];
        int cnt = 0;
        
        for (int num : arr) {
            if (cnt == 0)
                res = num;
            cnt += (num == res) ? 1 : -1;
        }
        return (res);
    }
};