class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> res;
        for (int i = 0; i < 9; i++) {
            string x = "";
            for (int j = i; j < 9; j++) {
                x += s[j];
                int num = stoi(x);
                if (low <= num && num <= high) {
                    res.push_back(num);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};