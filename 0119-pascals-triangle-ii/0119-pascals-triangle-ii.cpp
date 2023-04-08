class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return (vector<int>(1, 1));
        vector<int> ans;
        ans.push_back(1);
        for (int i = 1; i < rowIndex; i++) {
            long long op1 = rowIndex;
            long long op2 = i;
            for (int j = 1; j < i; j++) {
                if (op1 % (i - j) == 0) {
                    op1 /= (i - j);
                    op1 *= (rowIndex - j);
                }
                else {
                    op1 *= (rowIndex - j);
                    op2 *= (i - j);    
                }
            }
            ans.push_back(op1 / op2);
        }
        ans.push_back(1);
        return ans;
    }
};