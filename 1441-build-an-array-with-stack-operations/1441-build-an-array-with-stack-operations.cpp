class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int t = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (t == target.size())
                break;
            
            if (target[t] == i) {
                res.push_back("Push");
                t++;
            }
            else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};