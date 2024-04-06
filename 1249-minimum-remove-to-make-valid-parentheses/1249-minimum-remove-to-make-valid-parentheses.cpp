class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (st.empty() == true)
                    s[i] = '*';
                else {
                    st.pop();
                }
            }
        }

        while (st.empty() == false) {
            s[st.top()] = '*';
            st.pop();
        }

        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '*')
                res += s[i];
        }
        return res;
    }
};