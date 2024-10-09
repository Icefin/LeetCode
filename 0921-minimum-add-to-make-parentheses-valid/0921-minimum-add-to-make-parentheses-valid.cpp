class Solution {
public:
    int minAddToMakeValid(string s) {
        std::stack<char> st;
        
        for (int i = 0; i < s.length(); ++i) {
            if (st.empty())
                st.push(s[i]);
            else {
                if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
};