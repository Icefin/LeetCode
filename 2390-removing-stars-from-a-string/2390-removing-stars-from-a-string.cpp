class Solution {
public:
    string removeStars(string s) {
        deque<char> dq;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                dq.pop_back();
                continue;
            }
            dq.push_back(s[i]);
        }
        string res = "";
        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
        }
        return res;
    }
};