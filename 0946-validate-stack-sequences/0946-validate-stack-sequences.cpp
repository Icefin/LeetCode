class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            if (popped[idx] != st.top())
                continue;
            while (!st.empty() && popped[idx] == st.top()) {
                st.pop();
                idx++;
            }
        }
        return st.empty();
    }
};