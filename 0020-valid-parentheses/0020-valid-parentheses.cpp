class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            char curr = st.top();
            if (curr == '(' && s[i] == ')') {
                st.pop();
            }
            else if (curr == '{' && s[i] == '}') {
                st.pop();
            }
            else if (curr == '[' && s[i] == ']') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};