class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        int left_most = 0;
        if (left.empty() == false)
            left_most = left.back();
        int right_most = 0;
        if (right.empty() == false)
            right_most = n - right[0];
        return max(left_most, right_most);
    }
};