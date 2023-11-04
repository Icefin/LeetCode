class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int left_most = 0;
        for (int pos : left) {
            if (pos > left_most)
                left_most = pos;
        }
        
        int right_most = n;
        for (int pos : right) {
            if (pos < right_most)
                right_most = pos;
        }
        
        return max(left_most, n - right_most);
    }
};