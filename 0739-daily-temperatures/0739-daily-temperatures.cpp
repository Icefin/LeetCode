class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> res(n, 0);
        std::stack<std::pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            while (st.empty() == false && st.top().first < temperatures[i]) {
                res[st.top().second] = i - st.top().second; st.pop();
            }
            st.push({temperatures[i], i});
        }
        while (st.empty() == false) {
            res[st.top().second] = 0; st.pop();
        }
        return res;
    }
};